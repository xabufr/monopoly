#ifndef GROUPETERRAIN_H_INCLUDED
#define GROUPETERRAIN_H_INCLUDED

#include <string>
#include <list>
#include <SFML/Graphics/Color.hpp>

class Joueur;
class CaseTerrain;
class GroupeTerrain
{
public:
    GroupeTerrain(const sf::Color& color, const std::string& nom, int prix);
    sf::Color color() const;
    std::string getNom() const;
    int prix_construction() const;
    Joueur* joueurMonopole() const;
    std::list<CaseTerrain*> getCasesTerrain() const;
    void addCase(CaseTerrain*);
private:
    int m_prix_construction;
    sf::Color m_color;
    std::string m_nom;
    std::list<CaseTerrain*> m_case_terrain;
};
#endif // GROUPETERRAIN_H_INCLUDED
