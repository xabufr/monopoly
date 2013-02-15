#include "groupeterrain.h"


GroupeTerrain::GroupeTerrain(const sf::Color color, const std::string& nom, const int prix):
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

}

void GroupeTerrain::addCase(CaseTerrain* c)
{
    m_case_terrain.push_back(c);
}
