#ifndef CASETERRAIN_H_INCLUDED
#define CASETERRAIN_H_INCLUDED

#include "case.h"

class Joueur;
class CaseTerrain : public Case
{
public:
	CaseTerrain(size_t id, const std::string& nom);
	virtual void joueurArrive(Joueur*);
	virtual void joueurPart(Joueur*);
	virtual void joueurPasse(Joueur*);
	virtual bool peutAppartenir() const;
	virtual bool peutAcheter(const Joueur*) const;
	virtual void acheter(Joueur*);

	virtual int prixAchat() const;
	virtual bool estAchete() const;
	virtual void acheter(Joueur*);
	virtual int valeur_hypotheque() const;
    virtual void hypothequer();
    virtual bool estEnHypotheque() const;
    virtual int loyer() const;
    virtual bool peutConstruire() const;

    int tarif() const;
private:
    int m_nombre_maison;
    static int m_loyer[6];
};

#endif // CASETERRAIN_H_INCLUDED
