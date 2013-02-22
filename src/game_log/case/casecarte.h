#ifndef CASECARTE_H_INCLUDED
#define CASECARTE_H_INCLUDED

#include "case.h"

class PaquetCarte;
class CaseCarte : public Case
{
public:
	CaseCarte(size_t id, PaquetCarte*);
	virtual void joueurArrive(Joueur*);
private:
    PaquetCarte *m_paquet;
};

#endif // CASECARTE_H_INCLUDED
