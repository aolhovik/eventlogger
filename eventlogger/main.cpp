#include "event.h"
#include "loggingServer.h"
#include "producer.h"
#include "subscriber.h"

#include "stacktracer.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <algorithm>

using namespace std::chrono_literals;

typedef std::shared_ptr<Producer> t_PtrProducer;

int
main ()
{
  Stacktracer log ("main");

  try
    {
      // create participants
      LoggingServer &srv = LoggingServer::instance ();

      Subscriber sub0 (0, &srv);
      Subscriber sub1 (1, &srv);
      srv.subscribe (&sub0);
      srv.subscribe (&sub1);

      srv.subscribe(nullptr);

      std::list<t_PtrProducer> Producers;
      for (int i = 0; i < 16; ++i)
	{
	  Producers.push_back (t_PtrProducer (new Producer (&srv)));
	}

      // start system; server starts automatically on creation
      for (auto ptr : Producers)
	{
	  ptr->start ();
	}

      // wait some and detach 1 sub
      std::this_thread::sleep_for (2s);
      srv.unsubscribe (&sub1);
      std::cout << "subscriber 1 detached" << std::endl;

      // wait some and stop system; server stops by itself on timeout
      std::this_thread::sleep_for (2s);
      srv.stop ();

      // FIXME range-for looks sO muCH mORE BETTER!
      std::for_each (Producers.begin (), Producers.end (), []
      (t_PtrProducer ptr)
	{ ptr->stop();});
    }
  catch (std::exception &e)
    {
      std::cout << "fatal error: " << e.what () << std::endl;
    }
}
