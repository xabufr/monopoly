#ifndef CASECOMPAGNIE_H_INCLUDED
#define CASECOMPAGNIE_H_INCLUDED

#include "casepropriete.h"

class Joueur;
class CaseCompagnie : public CasePropriete
{
public:
	CaseCompagnie(size_t id, const std::string& nom);
	virtual void joueurArrive(Joueur*);
	virtual int loyer() const;
    void setMultiplicateur(int index, int value);
	virtual std::string description() const;
private:
    int m_multiplicateur[2];
};
#endif // CASECOMPAGNIE_H_INCLUDED
