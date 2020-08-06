#include "stacktracer.h"

Stacktracer::Stacktracer(const std::string &Blockname, std::ostream &out) :
		_Blockname(Blockname), _out(out) {
	_out << _Blockname << " --->" << std::endl;
}

Stacktracer::~Stacktracer() {
	_out << _Blockname << " <---" << std::endl;
}
