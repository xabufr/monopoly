#include "groupeterrain.h"
#include "caseterrain.h"


GroupeTerrain::GroupeTerrain(const sf::Color& color, const std::string& nom, int prix):
m_color(color), m_nom(nom), m_prix_construction(prix)
{

}

sf::Color GroupeTerrain::color() const
{
    return m_color;
}

std::string GroupeTerrain::getNom() const
{
    return m_nom;
}

int GroupeTerrain::prix_construction() const
{
    return m_prix_construction;
}

Joueur* GroupeTerrain::joueurMonopole() const
{
    CaseTerrain* current=(*m_case_terrain.begin());

    for (auto it=m_case_terrain.begin(); it!=m_case_terrain.end(); ++it)
    {
        if (current->proprietaire() == nullptr || current->proprietaire() != ((CaseTerrain*)(*it))->proprietaire())
            return nullptr;
    }
    return current->proprietaire();
}

std::list<CaseTerrain*> GroupeTerrain::getCasesTerrain() const
{
    return m_case_terrain;
}


void GroupeTerrain::addCase(CaseTerrain* c)
{
    m_case_terrain.push_back(c);
}
