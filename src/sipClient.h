#ifndef Included_SipClient_H
#define Included_SipClient_H

#include "sipRequest.h"

class SipClient {
public:
	virtual int send(SipRequest::Method method) = 0;
	virtual void set_timeout(timeval timeout) {};
};

#endif
