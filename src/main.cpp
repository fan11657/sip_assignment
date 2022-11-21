#include "sipUdpClient.h"
#include "sipRetryClient.h"
#include "iostream"

using namespace std;
int main(int argc, char* argv[])
{
	if (argc < 3) {
		cout << "Missing Arguments" << endl;
		return -1;
	}

	SipUser to = {};
	to.user_name = "ping";
	to.ip = argv[1];
	to.port = stoi(argv[2]);

	SipUser from = {};
	from.user_name = "ping";
	from.ip = "0.0.0.0";
	from.port = 60707;

	SipUdpClient sip_udp_client(from, to, "sipping");
	SipRetryClient sip_retry_client((SipClient *)&sip_udp_client, 10);
	int result = sip_retry_client.send(SipRequest::Method::OPTIONS);
	cout << result << endl;
	return 0;
}
