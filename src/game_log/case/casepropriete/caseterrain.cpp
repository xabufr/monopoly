#include "caseterrain.h"
#include "../../joueur.h"
#include "groupeterrain.h"

CaseTerrain::CaseTerrain(size_t id, const std::string& nom):CasePropriete(id, nom), m_nombre_maison(0)
{

}
int CaseTerrain::loyer() const
{
    return m_loyer[m_nombre_maison];
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
