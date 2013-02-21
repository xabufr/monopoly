#include "casedepart.h"
#include "../joueur.h"

CaseDepart::CaseDepart(size_t id, int credit):Case(id, "Départ"), m_value_credit(credit)
{

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
