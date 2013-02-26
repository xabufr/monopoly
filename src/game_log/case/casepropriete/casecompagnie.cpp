#include "casecompagnie.h"
#include "../../joueur.h"

CaseCompagnie::CaseCompagnie(size_t id, const std::string& nom):CasePropriete(id, nom)
{

}

int CaseCompagnie::loyer() const
{
    return (m_multiplicateur[(CasePropriete::proprietaire()->getNombreGare()-1)]*CasePropriete::proprietaire()->dernierLancer());
}
void CaseCompagnie::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    if (CasePropriete::proprietaire() == nullptr || CasePropriete::proprietaire() == j || estEnHypotheque())
        return;

    j->payer(m_multiplicateur[CasePropriete::proprietaire()->getNombreGare()-1]*j->dernierLancer());
    CasePropriete::proprietaire()->crediter(m_multiplicateur[CasePropriete::proprietaire()->getNombreGare()-1]*j->dernierLancer());
}
void CaseCompagnie::setMultiplicateur(int index, int value)
{
    m_multiplicateur[index] = value;
}
