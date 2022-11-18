#include "sipClient.h"

class SipRetryClient : SipClient {
public:
	SipRetryClient(SipClient *sip_client, int max_retry);
	int send(SipRequest::Method method);
	void set_timeout(timeval timeout);
private:
	SipClient *sip_client;
	int max_retry;
	timeval max_timeout;
	timeval double_time(timeval time);
};
