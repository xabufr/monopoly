#ifndef CASEPROPRIETE_H_INCLUDED
#define CASEPROPRIETE_H_INCLUDED

#include "../case.h"

class Joueur;
class CasePropriete : public Case
{
public:
	CasePropriete(size_t id, const std::string& nom);
	virtual bool peutAppartenir() const;
	virtual void joueurArrive(Joueur*);
	virtual int prixAchat() const;
	virtual bool estAchete() const;
	virtual void acheter(Joueur*);
	virtual int valeur_hypotheque() const;
    virtual void hypothequer(bool=true);
    virtual void deshypothequer();
    virtual bool estEnHypotheque() const;
    virtual int loyer() const;
    virtual bool peutConstruire() const;

    void setPrix(int);
    void setHypotheque(int);
    Joueur* proprietaire() const;
    void setProprietaire(Joueur*);
private:
    int m_prix;
    int m_hypotheque;
    bool m_en_hypotheque;
    Joueur *m_proprietaire;
};

#endif // CASEPROPRIETE_H_INCLUDED
