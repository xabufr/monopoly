#include "casegare.h"
#include "../../joueur.h"

CaseGare::CaseGare(size_t id, const std::string& nom):CasePropriete(id, nom)
{

}

void CaseGare::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    if (CasePropriete::proprietaire() == nullptr || CasePropriete::proprietaire() == j)
        return;

    j->payer(m_loyer_par_gare[CasePropriete::proprietaire()->getNombreGare()-1]);
    CasePropriete::proprietaire()->crediter(m_loyer_par_gare[CasePropriete::proprietaire()->getNombreGare()-1]);
}

void CaseGare::setLoyerParGare(int index, int value)
{
    m_loyer_par_gare[index] = value;
}

int CaseGare::loyer() const
{
    return m_loyer_par_gare[CasePropriete::proprietaire()->getNombreGare()-1];
}
