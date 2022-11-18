#include "sipUdpClient.h"
#include "sipRetryClient.h"
#include "iostream"

using namespace std;
int main()
{
	SipUser to = {};
	to.user_name = "ping";
	to.ip = "0.0.0.0";
	to.port = 5060;

	SipUser from = {};
	from.user_name = "ping";
	from.ip = "0.0.0.0";
	from.port = 5061;

	SipUdpClient sip_udp_client(from, to, "sipping");
	SipRetryClient sip_retry_client((SipClient *)&sip_udp_client, 10);
	int result = sip_retry_client.send(SipRequest::Method::OPTIONS);
	cout << result << endl;
	return 0;
}
