#ifndef CASEPARKINGGRATUIT_H_INCLUDED
#define CASEPARKINGGRATUIT_H_INCLUDED

#include "case.h"

class CaseParkingGratuit : public Case
{
public:
	CaseParkingGratuit(size_t id, const std::string& nom);
};

#endif // CASEPARKINGGRATUIT_H_INCLUDED