#include "random.h"

#include <cstdlib>
#include <cassert>

namespace utils {

unsigned int random(unsigned int iMin, unsigned iMax) {
	assert(iMax > iMin);
	return iMin + rand() % (iMax - iMin);
}

unsigned int random(unsigned iMax) {
	return random(0, iMax);
}

}
