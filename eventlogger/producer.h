#ifndef PRODUCER_H_
#define PRODUCER_H_

#include "event.h"
#include "runnable.h"

class LoggingServer;

/// Simple Event Producers; randomly generates events
class Producer: public Runnable
{
public:
	Producer(LoggingServer*);

	virtual ~Producer();

protected:
	virtual int onIdle();
	virtual Event::t_Ptr produceEvent();

private:

	LoggingServer *_srv;
};

#endif // PRODUCER_H_
