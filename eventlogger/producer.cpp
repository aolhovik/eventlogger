#include "producer.h"
#include "loggingServer.h"
#include "stacktracer.h"
#include "random.h"

#include <limits>

Producer::Producer(LoggingServer *pSrv) :
		_srv(pSrv) {
}

Producer::~Producer() {
}

int Producer::onIdle() {
	if (_srv != nullptr) {
		_srv->push(produceEvent());
	}

	return utils::random(100, 250);
}

Event::t_Ptr Producer::produceEvent() {
	Event::t_Ptr p = std::make_shared<Event>();
	p->id = utils::random(std::numeric_limits<unsigned int>::max());
	p->loc_code = utils::random(128);
	p->type = utils::random(8);
	return p;
}
