#ifndef CASECARTE_H_INCLUDED
#define CASECARTE_H_INCLUDED

#include "case.h"

class PaquetCarte;
class CaseCarte : public Case
{
public:
	CaseCarte(size_t id, const std::string& nom);
	virtual void joueurArrive(Joueur*);
	void setPaquet(PaquetCarte*);
private:
    PaquetCarte *m_paquet;
};

#endif // CASECARTE_H_INCLUDED
