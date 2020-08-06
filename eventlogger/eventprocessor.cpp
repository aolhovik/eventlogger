#include "eventprocessor.h"

#include <exception>

void EventProcessor::push(Event::t_Ptr ptr) {
	std::lock_guard<std::mutex> GuardEvents(_MutexEvents);
	_Events.push(ptr);
}

Event::t_Ptr EventProcessor::pop() {
	Event::t_Ptr ptr;
	if (isEmpty()) {
		throw std::runtime_error("EventProcessor::pop when empty");
	} else {
		std::lock_guard<std::mutex> GuardEvents(_MutexEvents);
		ptr = _Events.front();
		_Events.pop();
	}
	return ptr;
}

bool EventProcessor::isEmpty() {
	/// FIXME: it's fast enough not to bother guarding
	return _Events.empty();
}
