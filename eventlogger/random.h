#ifndef RANDOM_H_
#define RANDOM_H_

namespace utils {

/// Return random number in [iMin, iMax) range
unsigned int random(unsigned int iMin, unsigned iMax);

/// Return random number in [0, iMax) range
unsigned int random(unsigned iMax);
}

#endif /* RANDOM_H_ */
