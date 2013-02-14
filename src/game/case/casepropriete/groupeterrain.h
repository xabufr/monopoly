#ifndef GROUPETERRAIN_H_INCLUDED
#define GROUPETERRAIN_H_INCLUDED

#include <string>

class Joueur;
class CaseTerrain;
class GroupeTerrain
{
public:
    GroupeTerrain(const sf::Color color, const std::string& nom, const int prix);
    sf::Color color() const;
    std::string getNom() const;
    int prix_construction() const;
    joueur joueurMonopole();
private:
    static int m_prix_construction;
    static sf::Color m_color;
    static std::string m_nom;
    CaseTerrain* m_case[];
};
#endif // GROUPETERRAIN_H_INCLUDED
