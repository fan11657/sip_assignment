#include <errno.h>
#include <sys/time.h>
#include "sipRetryClient.h"

SipRetryClient::SipRetryClient(SipClient *sip_client, int max_retry) {
	this->sip_client = sip_client;
	this->max_retry = max_retry;
	this->max_timeout = timeval{ 8, 0 };
}

int SipRetryClient::send(SipRequest::Method method) {
	timeval timeout{ 0, 500000 };
	for (int retry = max_retry; retry >= 0; retry--) {
		sip_client->set_timeout(timeout);
		int result = sip_client->send(method);
		if (result > 0) {
			return result;
		}
		if (errno == 0) {
			return -1;
		}

		timeout = double_time(timeout);
		if (timercmp(&timeout, &max_timeout, > )) {
			timeout = max_timeout;
		}
	}
	return -1;
}

timeval SipRetryClient::double_time(timeval time) {
	timeval doubled_time;
	timeradd(&time, &time, &doubled_time);
	return doubled_time;
}

void SipRetryClient::set_timeout(timeval timeout) {
	sip_client->set_timeout(timeout);
}