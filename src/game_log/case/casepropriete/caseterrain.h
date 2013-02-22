#ifndef CASETERRAIN_H_INCLUDED
#define CASETERRAIN_H_INCLUDED

#include "casepropriete.h"

class Joueur;
class GroupeTerrain;
class CaseTerrain : public CasePropriete
{
public:
	CaseTerrain(size_t id, const std::string& nom);
	virtual void joueurArrive(Joueur*);
	virtual int loyer() const;
	virtual void acheter(Joueur*);
	virtual bool peutConstruire() const;
	void setMaisons(int);

    void setGroupe(GroupeTerrain*);
    int tarif() const;
    int maisons() const;
	void setLoyer(int index, int value);
    // 5 = hotel
private:
    int m_nombre_maison;
    int m_loyer[6];
    GroupeTerrain* m_groupe;
};

#endif // CASETERRAIN_H_INCLUDED
