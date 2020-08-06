#include "runnable.h"
#include "stacktracer.h"

#include <chrono>
using namespace std::chrono_literals;
// duration in format 1mss

Runnable::Runnable() :
		_State(IDLE) {
}

Runnable::~Runnable() {
	if (RUNNING == _State) {
		stop();
	}
}

Runnable::tState Runnable::start() {
	Stacktracer log("Runnable::start");

	if (_State != IDLE) {
		throw std::logic_error("Runnable.start() while not stopped.");
	}
	_State = RUNNING;
	_Thread = std::thread(&Runnable::run, this);

	return getState();
}

Runnable::tState Runnable::stop() {
	Stacktracer log("Runnable::stop");

	if (_State != RUNNING) {
		throw std::logic_error("Runnable.stop() while not running.");
	}

	_State = STOPPING;
	_Thread.join();
	_State = STOPPED;

	return getState();
}

void Runnable::run() {
	Stacktracer log("Runnable::run");

	while (RUNNING == _State) {
		int iSleep = onIdle();
		if (iSleep > 0) {
			std::this_thread::sleep_for(
					std::chrono::duration<int, std::milli>(1ms) * iSleep);
		}
	}
}

Runnable::tState Runnable::getState() const {
	return _State;
}
