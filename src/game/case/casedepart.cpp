#include "casedepart.h"
#include "../joueur.h"

CaseDepart::CaseDepart(size_t id, int value, const std::string& nom):Case(id, nom),
m_value_credit(value)
{

}

int CaseDepart::getValueCredit() const
{
    return m_value_credit;
}

void CaseDepart::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    joueurPasse(j);
}

void CaseDepart::joueurPasse(Joueur* j)
{
    j->crediter(m_value_credit);
}
