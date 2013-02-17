#ifndef CASEGARE_H_INCLUDED
#define CASEGARE_H_INCLUDED

#include "../case.h"

class Joueur;
class CasePropriete : public Case
{
public:
	CasePropriete(size_t id, const std::string& nom);
	virtual void joueurArrive(Joueur*);
	virtual void joueurPart(Joueur*);
	virtual void joueurPasse(Joueur*);
	virtual bool peutAppartenir() const;
	virtual bool peutAcheter(const Joueur*) const;

	virtual int prixAchat() const;
	virtual bool estAchete() const;
	virtual void acheter(Joueur*);
	virtual int valeur_hypotheque() const;
    virtual void hypothequer();
    virtual bool estEnHypotheque() const;
    virtual int loyer() const;
    virtual bool peutConstruire() const;
private:
    static int m_loyer_par_gare;
};
#endif // CASEGARE_H_INCLUDED
