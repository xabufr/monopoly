#ifndef CASEDEPART_H_INCLUDED
#define CASEDEPART_H_INCLUDED

#include "case.h"

class Joueur;
class CaseDepart : public Case
{
public:
	CaseDepart(size_t id, int value, const std::string& nom);
	int getValueCredit() const;
	virtual void joueurArrive(Joueur*);
	virtual void joueurPasse(Joueur*);
private:
	int m_value_credit;
};

#endif // CASEDEPART_H_INCLUDED
