#include "casetaxe.h"
#include "../joueur.h"

CaseTaxe::CaseTaxe(size_t id, size_t value, const std::string& nom):Case(id, nom)
{

}

int CaseTaxe::getValue() const
{
    return m_value;
}

void CaseTaxe::setValue(int v)
{
    m_value = v;
}

void CaseTaxe::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    j->payer(m_value);
}
