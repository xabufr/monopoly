#ifndef CASETAXE_H_INCLUDED
#define CASETAXE_H_INCLUDED

#include "case.h"

class Joueur;
class CaseTaxe : public Case
{
public:
	CaseTaxe(size_t id, size_t value, const std::string& nom);
	int getValue() const;
	virtual void joueurArrive(Joueur*);
private:
    int m_value;
};

#endif // CASETAXE_H_INCLUDED
