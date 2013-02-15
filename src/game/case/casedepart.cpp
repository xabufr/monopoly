#include "casedepart.h"
#include "../joueur.h"

CaseDepart::CaseDepart(size_t id, const std::string& nom):Case(id, nom)
{

}

void CaseDepart::setValueCredit(int v)
{
    m_value_credit = v;
}

int CaseDepart::getValueCredit()
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
