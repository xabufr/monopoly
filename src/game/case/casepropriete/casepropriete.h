#ifndef CASEPROPRIETE_H_INCLUDED
#define CASEPROPRIETE_H_INCLUDED

#include "../case.h"

class Joueur;
class CasePropriete : public Case
{
public:
	CasePropriete(size_t id, const std::string& nom, int prix, int hypotheque);
	virtual int prixAchat() const;
	virtual bool estAchete() const;
	virtual void acheter(Joueur*);
	virtual int valeur_hypotheque() const;
    virtual void hypothequer();
    virtual bool estEnHypotheque() const;
    virtual int loyer() const;
    virtual bool peutConstruire() const;

    Joueur* proprietaire() const;
private:
    int m_prix;
    int m_hypotheque;
    Joueur *m_proprietaire;
};

#endif // CASEPROPRIETE_H_INCLUDED
