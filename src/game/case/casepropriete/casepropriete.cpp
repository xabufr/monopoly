#include "casepropriete.h"
#include "../../joueur.h"


CasePropriete::CasePropriete(size_t id, const std::string& nom, int prix, int hypotheque):Case(id, nom),
m_prix(prix),
m_hypotheque(hypotheque),
m_propietaire(nullptr),
m_en_hypotheque(false)
{

}

int CasePropriete::prixAchat() const
{
    return m_prix;
}

bool CasePropriete::estAchete() const
{
    return (m_propietaire != nullptr);
}

void CasePropriete::acheter(Joueur* j)
{
    if (j->argent >= m_prix)
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
    m_propietaire->crediter(m_hypotheque);
    m_en_hypotheque = true;
}

void CasePropriete::deshypothequer()
{
    int value = (m_hypotheque*0.01f)+m_hypotheque;

    if (m_propietaire->argent() > value)
    {
        m_propietaire->payer(value);
        m_en_hypotheque = false;
    }
}

bool CasePropriete::estEnHypotheque() const
{
    return m_en_hypotheque;
}

int CasePropriete::loyer() const
{

}

bool CasePropriete::peutConstruire() const
{
    return false;
}

Joueur CasePropriete::proprietaire() const
{
    return m_proprietaire;
}
