#include "SipUdpClient.h"
#include "SipRetryClient.h"
#include "iostream"

using namespace std;
int main()
{
	SipUdpClient sip_udp_client("0.0.0.0", 5060, "sipping");
	SipRetryClient sip_retry_client((SipClient *)&sip_udp_client, 10);
	int result = sip_retry_client.send(SipRequest::Method::OPTIONS);
	cout << result << endl;
	return 0;
}
