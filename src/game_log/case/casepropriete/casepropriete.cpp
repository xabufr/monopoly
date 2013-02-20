#include "casepropriete.h"
#include "../../joueur.h"

CasePropriete::CasePropriete(size_t id, const std::string& nom):Case(id, nom),
m_proprietaire(nullptr)
{

}

bool CasePropriete::peutAppartenir() const
{
    return true;
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
    m_proprietaire->crediter(m_hypotheque);
    m_en_hypotheque = true;
}

void CasePropriete::deshypothequer()
{
    int value = (m_hypotheque*0.01f)+m_hypotheque;

    if (m_proprietaire->argent() > value)
    {
        m_proprietaire->payer(value);
        m_en_hypotheque = false;
    }
}

bool CasePropriete::estEnHypotheque() const
{
    return m_en_hypotheque;
}

int CasePropriete::loyer() const
{
    return 0;
}

bool CasePropriete::peutConstruire() const
{
    return false;
}

Joueur* CasePropriete::proprietaire() const
{
    return m_proprietaire;
}

void CasePropriete::setProprietaire(Joueur*j)
{
    m_proprietaire = j;
}

void CasePropriete::setPrix(int p)
{
    m_prix = p;
}

void CasePropriete::setHypotheque(int h)
{
    m_hypotheque = h;
}
