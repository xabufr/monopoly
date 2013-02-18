#ifndef CASEALLERENPRISON_H_INCLUDED
#define CASEALLERENPRISON_H_INCLUDED

#include "case.h"

class Joueur;
class CaseAllerEnPrison : public Case
{
public:
	CaseAllerEnPrison(size_t id, const std::string& nom);
	virtual void joueurArrive(Joueur*);
};

#endif // CASEALLERENPRISON_H_INCLUDED
