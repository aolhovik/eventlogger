#ifndef LOGGINGSERVER_H_
#define LOGGINGSERVER_H_

#include "event.h"
#include "runnable.h"
#include "subscriber.h"

#include <list>
#include <queue>
#include <mutex>

class LoggingServer: public Runnable
{
public:
	void subscribe(Subscriber*);
	void unsubscribe(Subscriber*);

	static LoggingServer& instance();

	/// posts an event to be processed at a later time
	void post(Event::t_Ptr);

protected:

	virtual int onIdle();

private:
	void notify(Event::t_Ptr&);

	std::list<Subscriber*> _Subs;
	static LoggingServer *_pInstance;

	// FIXME: do I want a priority queue here?
	std::queue<Event::t_Ptr> _Events;
	std::mutex _MutexEvents;

	// TODO: move to config some other day
	unsigned long int _iSleepTime; /// Sleep on idle in ms

	Event::t_Id _IdLastUsed;

	LoggingServer();
};

#endif // LOGGINGSERVER_H_
