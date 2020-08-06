#ifndef LOGGINGSERVER_H_
#define LOGGINGSERVER_H_

#include "event.h"
#include "runnable.h"
#include "subscriber.h"
#include "eventprocessor.h"

#include <list>
#include <queue>

class LoggingServer: public Runnable, public EventProcessor {
public:
	void subscribe(Subscriber*);
	void unsubscribe(Subscriber*);

	static LoggingServer& instance();

protected:

	virtual int onIdle();

private:
	void notify(Event::t_Ptr);

	std::list<Subscriber*> _Subs;
	static LoggingServer *_pInstance;

	// TODO: move to config some other day
	unsigned long int _iSleepTime; /// Sleep on idle in ms

	LoggingServer();
};

#endif // LOGGINGSERVER_H_
