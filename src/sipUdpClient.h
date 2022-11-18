#include <string>
#include <netdb.h>
#include "sipClient.h"

class SipUdpClient : SipClient {
public:
	SipUdpClient(string ip, int port, string user_agent);
	~SipUdpClient();
	int send(SipRequest::Method method);
	void set_timeout(timeval timeout);
private:
	int socket_id;
	string ip;
	int port;
	struct sockaddr_in socket_address;
	struct timeval timeout;
	string user_agent;
};
