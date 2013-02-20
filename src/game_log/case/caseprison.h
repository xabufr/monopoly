#ifndef CASEPRISON_H_INCLUDED
#define CASEPRISON_H_INCLUDED

#include "case.h"

class Joueur;
class CasePrison : public Case
{
public:
	CasePrison(size_t id);
	virtual void joueurArrive(Joueur*);
	virtual void joueurPart(Joueur*);
private:
    std::list<Joueur*> m_prisonnier;
};

#endif // CASEPRISON_H_INCLUDED
