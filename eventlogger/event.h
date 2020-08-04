#ifndef EVENT_H_
#define EVENT_H_

#include <ostream>
#include <string>
#include <memory>

/// Base class for events.
struct Event
{
	typedef	std::shared_ptr<Event> t_Ptr;

	typedef unsigned int t_Id;
	unsigned int type;
	t_Id id;
	std::string description;
	unsigned int loc_code;
};

std::ostream& operator<< (std::ostream& out, const Event& e);

#endif // EVENT_H_
