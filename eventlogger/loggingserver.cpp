#include "loggingServer.h"
#include "stacktracer.h"

#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std::chrono_literals;

LoggingServer *LoggingServer::_pInstance = nullptr;

LoggingServer&
LoggingServer::instance ()
{
  if (nullptr == _pInstance)
    {
      _pInstance = new LoggingServer ();
      _pInstance->start (); // FIXME: it crashes from .ctor
    }

  return *_pInstance;
}

LoggingServer::LoggingServer (): _iSleepTime(250), _IdLastUsed(0)
{
}

void
LoggingServer::subscribe (Subscriber *pSub)
{
  if (nullptr == pSub)
    {
      throw std::invalid_argument("LoggingServer::subscribe nullptr");
    }

  Stacktracer log ("LoggingServer::subscribe");
  log._out << "subsciber._id=" << pSub->getId () << std::endl;
  _Subs.push_back (pSub);
}

void
LoggingServer::unsubscribe (Subscriber *pSub)
{
  if (nullptr == pSub)
    {
      throw std::invalid_argument("LoggingServer::unsubscribe nullptr");
    }

  Stacktracer log ("LoggingServer::unsubscribe");
  log._out << "subsciber._id=" << pSub->getId () << std::endl;

  _Subs.remove (pSub);
}

void
LoggingServer::notify (Event::t_Ptr &ptr)
{
  for (auto s : _Subs)
    {
      s->notify (ptr);
    }
}

void
LoggingServer::post (Event::t_Ptr ptr)
{
//  Stacktracer ("LoggingServer::post");

  std::lock_guard<std::mutex> GuardEvents(_MutexEvents);
  // FIXME: we want events id to be unique across all producers
  _IdLastUsed++;
  ptr->id = _IdLastUsed;
  _Events.push (ptr);
}

int
LoggingServer::onIdle ()
{
  while (!_Events.empty ())
    {
      Event::t_Ptr ptr;
	{
	  std::lock_guard<std::mutex> GuardEvents (_MutexEvents);
	  ptr = _Events.front ();
	  _Events.pop ();
	}

      notify (ptr);
    }

  return _iSleepTime;
}
