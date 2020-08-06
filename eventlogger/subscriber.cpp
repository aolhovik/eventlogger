
#include "subscriber.h"
#include "random.h"

#include <iostream>

Subscriber::Subscriber(t_id id, LoggingServer* pSrv) : _srv(pSrv), _id(id)
{}

Subscriber::~Subscriber()
{}

void Subscriber::update(Event::t_Ptr ptr)
{
	push(ptr);
}

Subscriber::t_id
Subscriber::getId() const
{
  return _id;
};

int
Subscriber::onIdle()
{
	while(!isEmpty())
	{
		Event::t_Ptr ptr = pop();
		std::cout << "Subsciber: id=" << getId() << "; Event: " << *ptr;
	}

	return utils::random(100, 500);
}
