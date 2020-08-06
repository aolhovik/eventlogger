
#ifndef EVENTPROCESSOR_H_
#define EVENTPROCESSOR_H_

#include "event.h"

#include <queue>
#include <mutex>

class EventProcessor
{
public:
	/// posts an event to be processed at a later time
	void push(Event::t_Ptr);

protected:
	Event::t_Ptr pop();
	bool isEmpty();

private:
	// FIXME: do I want a priority queue here?
	std::queue<Event::t_Ptr> _Events;
	std::mutex _MutexEvents;

};

#endif /* EVENTPROCESSOR_H_ */
