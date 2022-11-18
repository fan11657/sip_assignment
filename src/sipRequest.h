#ifndef Included_SipRequest_H
#define Included_SipRequest_H

#include <string>
using namespace std;
class SipRequest {
public:
	enum Method {
		REGISTER,
		INVITE,
		ACK,
		CANCEL,
		BYE,
		OPTIONS
	};
	enum Transport {
		TCP,
		UDP
	};
	SipRequest(Method method, Transport transport, string to, string from, string user_agent);
	string build_message();
private:
	Method method;
	Transport transport;
	string version;
	int max_forward;
	string to;
	string from;
	// A peer has unique tag
	string from_tag;
	// Every request/transaction has unique branch
	string branch;
	// Every dialog has unique call id
	string call_id;
	// Every request/transaction within a dialog increases CSeq
	int cseq;
	string user_agent;
	int content_length;
	string method_str();
	string transport_str();
};

#endif