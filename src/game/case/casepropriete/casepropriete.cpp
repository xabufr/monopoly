#include "casepropriete.h"
#include "../../joueur.h"


CasePropriete::CasePropriete(size_t id, const std::string& nom, int prix, int hypotheque):Case(id, nom),
m_prix(prix),
m_hypotheque(hypotheque),
m_proprietaire(nullptr)
{

}

int CasePropriete::prixAchat() const
{
    return m_prix;
}

bool CasePropriete::estAchete() const
{
    return (m_proprietaire != nullptr);
}

void CasePropriete::acheter(Joueur* j)
{
    if (j->argent() >= m_prix)
    {
        j->payer(m_prix);
        j->addPropriete(this);
        m_proprietaire = j;
    }
}

int CasePropriete::valeur_hypotheque() const
{
    return m_hypotheque;
}

void CasePropriete::hypothequer()
{

}

bool CasePropriete::estEnHypotheque() const
{

}

int CasePropriete::loyer() const
{

}

bool CasePropriete::peutConstruire() const
{
    return false;
}

Joueur* CasePropriete::proprietaire() const
{
    return m_proprietaire;
}
