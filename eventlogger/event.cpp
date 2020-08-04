
#include "event.h"

std::ostream& operator<< (std::ostream& out, const Event& e)
{
	out << "Event id=" << e.id << ", type=" << e.type << ", loc_code=" << e.loc_code << ", desc="<< e.description << std::endl;
	return out;
}
