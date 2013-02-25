#include "caseterrain.h"
#include "../../joueur.h"
#include "groupeterrain.h"

CaseTerrain::CaseTerrain(size_t id, const std::string& nom):CasePropriete(id, nom), m_nombre_maison(0)
{

}
void CaseTerrain::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    if (CasePropriete::proprietaire() != j)
        j->payer(m_loyer[m_nombre_maison]);
}
int CaseTerrain::loyer() const
{
    return m_loyer[m_nombre_maison];
}
void CaseTerrain::setGroupe(GroupeTerrain* g)
{
    m_groupe = g;
}
void CaseTerrain::acheter(Joueur* j)
{
    if (CasePropriete::proprietaire() == nullptr)
    {
        j->payer(CasePropriete::prixAchat());
        CasePropriete::setProprietaire(j);
    }
    else if ((CasePropriete::proprietaire() == j && peutConstruire()) && j->argent() >= (m_groupe->prix_construction()*(m_nombre_maison+1)))
        CasePropriete::proprietaire()->payer(m_groupe->prix_construction()*(++m_nombre_maison));

}
bool CaseTerrain::peutConstruire() const
{
    bool work=true;
    for (auto it=m_groupe->getCasesTerrain().begin(); it!= m_groupe->getCasesTerrain().end(); ++it)
    {
        if (m_nombre_maison > ((CaseTerrain*)(*it))->maisons() && m_nombre_maison == 5)
            return false;
    }
    return (CasePropriete::proprietaire() == m_groupe->joueurMonopole() && work);
}
int CaseTerrain::maisons() const
{
    return m_nombre_maison;
}
int CaseTerrain::tarif() const
{
    if (m_nombre_maison <= 4)
        return m_groupe->prix_construction();
    else
        return m_groupe->prix_construction()*5;
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