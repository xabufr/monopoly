#include "casecompagnie.h"
#include "../../joueur.h"
#include <boost/lexical_cast.hpp>

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
    if (proprietaire() == nullptr || proprietaire() == j || estEnHypotheque())
        return;

    j->payer(m_multiplicateur[proprietaire()->getNombreCompagnie()-1]*((int)j->dernierLancer()));
    CasePropriete::proprietaire()->crediter(m_multiplicateur[proprietaire()->getNombreCompagnie()-1]*((int)j->dernierLancer()));
}
void CaseCompagnie::setMultiplicateur(int index, int value)
{
    m_multiplicateur[index] = value;
}
std::string CaseCompagnie::description() const
{
	std::string desc = "Loyer: \n";
	for (size_t i = 0; i < 2; ++i)
	{
		desc += boost::lexical_cast<std::string>(i+1)+" compagnie(s) => montant des dés X "+ boost::lexical_cast<std::string>(m_multiplicateur[i]) + "\n";
	}
	desc += "Prix => " +  boost::lexical_cast<std::string>(prixAchat()) + " €";
	return desc;
}
