#include "caseterrain.h"
#include "../../joueur.h"
#include "groupeterrain.h"
#include <boost/lexical_cast.hpp>

CaseTerrain::CaseTerrain(size_t id, const std::string& nom):CasePropriete(id, nom), m_nombre_maison(0)
{

}
int CaseTerrain::loyer() const
{
    return m_loyer[m_nombre_maison] * ((int)(m_groupe->joueurMonopole()&&m_nombre_maison==0) ?2:1);
}
void CaseTerrain::setGroupe(GroupeTerrain* g)
{
    m_groupe = g;
	m_groupe->addCase(this);
}
void CaseTerrain::acheter(Joueur* j)
{
    if (CasePropriete::proprietaire() == nullptr && j->argent() >= CasePropriete::prixAchat())
    {
        j->payer(CasePropriete::prixAchat());
        CasePropriete::setProprietaire(j);
		j->addPropriete(this);
    }
    else if (CasePropriete::proprietaire() == j && peutConstruire() && j->argent() >= (m_groupe->prix_construction()))
    {
        CasePropriete::proprietaire()->payer(m_groupe->prix_construction());
        ++m_nombre_maison;
    }
}
void CaseTerrain::vendre(Joueur*)
{
    if (peutDetruire())
    {
        CasePropriete::proprietaire()->crediter(m_groupe->prix_construction());
        --m_nombre_maison;
    }
}
bool CaseTerrain::peutConstruire() const
{
	for (auto it=m_groupe->getCasesTerrain().begin(); it!= m_groupe->getCasesTerrain().end(); ++it)
	{
		if(*it==this)
			continue;
		if (m_nombre_maison > ((CaseTerrain*)(*it))->maisons() || m_nombre_maison == 5)
			return false;

	}
    return (CasePropriete::proprietaire() == m_groupe->joueurMonopole());
}
bool CaseTerrain::peutDetruire() const
{
    for (auto it=m_groupe->getCasesTerrain().begin(); it!= m_groupe->getCasesTerrain().end(); ++it)
	{
		if(*it==this)
			continue;
		if ((m_nombre_maison-1) == (((CaseTerrain*)(*it))->maisons()-1) && m_nombre_maison != 0)
			return true;

	}
    return false;
}
int CaseTerrain::maisons() const
{
    return m_nombre_maison;
}
int CaseTerrain::tarif() const
{
    return m_groupe->prix_construction();
}
void CaseTerrain::setLoyer(int index, int value)
{
	m_loyer[index] = value;
}
void CaseTerrain::setMaisons(int m)
{
	if(m>=0&&m<=5)
		m_nombre_maison=m;
}
std::string CaseTerrain::description() const
{
	std::string desc = "Loyers\n";
	desc += "Terrain nu => " + boost::lexical_cast<std::string>(m_loyer[0])+" €\n";
	for (size_t i = 1; i < 5; ++i)
	{
		desc += boost::lexical_cast<std::string>(i)+" maison(s) => " + boost::lexical_cast<std::string>(m_loyer[i]) + " €\n";
	}
	desc += "Hotel => " + boost::lexical_cast<std::string>(m_loyer[5]) + " €\n";
	desc += "Prix d'une maison: " + boost::lexical_cast<std::string>(m_groupe->prix_construction()) + " €\n";
	desc += "Prix => " + boost::lexical_cast<std::string>(prixAchat()) + " €";
	return desc;
}
