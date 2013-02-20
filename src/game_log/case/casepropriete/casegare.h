#ifndef CASEGARE_H_INCLUDED
#define CASEGARE_H_INCLUDED

#include "casepropriete.h"

class Joueur;
class CaseGare : public CasePropriete
{
public:
	CaseGare(size_t id, const std::string& nom);
	virtual void joueurArrive(Joueur*);
    void setLoyerParGare(int index, int value);

    virtual int loyer() const;
private:
    int m_loyer_par_gare[4];
};
#endif // CASEGARE_H_INCLUDED
