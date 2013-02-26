#include "casegare.h"
#include "../../joueur.h"
#include <boost/lexical_cast.hpp>

CaseGare::CaseGare(size_t id, const std::string& nom):CasePropriete(id, nom)
{

}
void CaseGare::setLoyerParGare(int index, int value)
{
    m_loyer_par_gare[index] = value;
}
int CaseGare::loyer() const
{
    return m_loyer_par_gare[CasePropriete::proprietaire()->getNombreGare()-1];
}
std::string CaseGare::description() const
{
	std::string desc="Loyers: \n";
	for (size_t i = 0; i < 4; ++i)
	{
		desc += boost::lexical_cast<std::string>(i+1);
		desc += " gare => " + boost::lexical_cast<std::string>(m_loyer_par_gare[i]) + " € \n";
	}
	return desc;
}
