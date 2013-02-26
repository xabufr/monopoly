#ifndef CASEALLERENPRISON_H_INCLUDED
#define CASEALLERENPRISON_H_INCLUDED

#include "case.h"

class Plateau;
class Joueur;
class CaseAllerEnPrison : public Case
{
public:
	CaseAllerEnPrison(size_t id, Plateau*);
	virtual void joueurArrive(Joueur*);
private:
	Plateau* m_plateau;
};

#endif // CASEALLERENPRISON_H_INCLUDED
