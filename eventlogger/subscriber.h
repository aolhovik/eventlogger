#ifndef SUBSCRIBER_H_
#define SUBSCRIBER_H_

#include "event.h"

class LoggingServer;

/// Base class for the Event Subscribers.
class Subscriber
{
public:
	typedef unsigned int t_id;
	Subscriber(t_id id,LoggingServer*);

	virtual void notify(Event::t_Ptr ptr);

	t_id getId() const;

	virtual ~Subscriber();
private:
	LoggingServer *_srv;
	t_id _id;
};

#endif // SUBSCRIBER_H_
