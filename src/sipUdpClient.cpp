#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h> 
#include "sipUdpClient.h"

SipUdpClient::SipUdpClient(SipUser from, SipUser to, string user_agent) {
	this->from = from;
	this->to = to;
	this->user_agent = user_agent;
	this->socket_id = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	set_timeout(timeval{ 0, 0 });
	
	memset(&(this->socket_address), 0, sizeof(this->socket_address));
	this->socket_address.sin_family = AF_INET;
	this->socket_address.sin_addr.s_addr = inet_addr(to.ip.c_str());
	this->socket_address.sin_port = htons(to.port);
}
SipUdpClient::~SipUdpClient() {
	close(socket_id);
}
int SipUdpClient::send(SipRequest::Method method) {
	SipRequest request(method, SipRequest::Transport::UDP, from, to, user_agent);
	string msg = request.build_message();
	int sent_len = sendto(socket_id, msg.c_str(), msg.length(), MSG_CONFIRM, (struct sockaddr*)&socket_address, sizeof(socket_address));
	if (sent_len < 0) {
		return -1;
	}

	setsockopt(socket_id, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

	const int BUFLEN = 1024;
	char recv_buffer[BUFLEN] = {};
	socklen_t addr_len = sizeof(socket_address);
	int recv_len = recvfrom(socket_id, recv_buffer, BUFLEN, 0, (sockaddr*)&socket_address, &addr_len);
	if (recv_len < 0) {
		return -1;
	}
	string recv = string(recv_buffer, recv_len);
	const int STATUS_CODE_LEN = 3;
	string status_code = recv.substr(recv.find(' ') + 1, STATUS_CODE_LEN);
	cout << recv << endl;
	if (status_code != "200") {
		return -1;
	}
	return 1;
}
void SipUdpClient::set_timeout(timeval timeout) {
	this->timeout = timeout;
}
