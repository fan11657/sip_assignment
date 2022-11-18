#include <chrono>
#include <sstream>
#include "sipRequest.h"
#include "utils.h"

SipRequest::SipRequest(Method method, Transport transport, SipUser from, SipUser to, string user_agent) {
	this->method = method;
	this->version = "SIP/2.0";
	this->transport = transport;
	this->max_forward = 70;
	this->from = from;
	this->to = to;
	const int TAG_LEN = 20;
	this->from_tag = RandomStrGenerator::generate(TAG_LEN);
	const int BRANCH_LEN = 20;
	this->branch = RandomStrGenerator::generate(BRANCH_LEN);
	const int CALL_ID_LEN = 20;
	this->call_id = RandomStrGenerator::generate(CALL_ID_LEN);
	this->cseq = 1;
	this->user_agent = user_agent;
	this->content_length = 0;
}
string SipRequest::build_message() {
	const char SPACE = ' ';
	const string MAGIC_COOKIE = "z9hG4bK";

	stringstream stream;
	stream << method_str() << SPACE << "sip:" << to.user_name << '@' << to.ip << SPACE << version << endl;
	stream << "Via:" << version << '/' << transport << SPACE << from.ip << ':' << from.port << ";branch=" << MAGIC_COOKIE << branch << endl;
	stream << "From:" << SPACE << "<sip:" << from.user_name << '@' << from.ip << ">;tag=" << from_tag << endl;
	stream << "To:" << SPACE << "<sip:" << to.user_name << '@' << to.ip << ">" << endl;
	stream << "Max-Forwards:" << SPACE << max_forward << endl;
	stream << "Contact:" << SPACE << "<sip:" << from.user_name << '@' << from.ip << ':' << from.port << ";transport=" << transport_str() << ">" << endl;
	stream << "Call-ID:" << SPACE << call_id << endl;
	stream << "CSeq:" << SPACE << cseq << SPACE << method_str() << endl;
	stream << "Supported:" << SPACE << "outbound" << endl;
	stream << "User-Agent:" << SPACE << user_agent << endl;
	stream << "Content-Length:" << SPACE << content_length << endl;

	return stream.str();
}

string SipRequest::method_str() {
	switch (method)
	{
	case REGISTER:
		return "REGISTER";
	case INVITE:
		return "INVITE";
	case ACK:
		return "ACK";
	case CANCEL:
		return "CANCEL";
	case BYE:
		return "BYE";;
	case OPTIONS:
		return "OPTIONS";
	default:
		return "";
	}
}

string SipRequest::transport_str() {
	switch (transport)
	{
	case TCP:
		return "TCP";
	case UDP:
		return "UDP";
	default:
		return "";
	}
}