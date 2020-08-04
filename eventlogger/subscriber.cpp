#include <iostream>
#include "subscriber.h"

Subscriber::Subscriber(t_id id, LoggingServer* pSrv) : _srv(pSrv), _id(id)
{}

Subscriber::~Subscriber()
{}

void Subscriber::notify(Event::t_Ptr ptr)
{
	std::cout << "Subsciber: id=" << _id << "; Event: " << *ptr;
}

Subscriber::t_id
Subscriber::getId() const
{
  return _id;
};
