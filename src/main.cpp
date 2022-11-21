#include "sipUdpClient.h"
#include "sipRetryClient.h"
#include "iostream"

using namespace std;
int main(int argc, char* argv[])
{
	if (argc < 4) {
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

	int max_retry = stoi(argv[3]);

	SipUdpClient sip_udp_client(from, to, "sipping");
	SipRetryClient sip_retry_client((SipClient *)&sip_udp_client, max_retry);
	int result = sip_retry_client.send(SipRequest::Method::OPTIONS);
	cout << result << endl;
	return 0;
}
