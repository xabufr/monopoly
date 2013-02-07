#ifndef POSITIONINFORMATIONS_H
#define POSITIONINFORMATIONS_H
/// @todo Documenter
struct PositionInformations
{
        PositionInformations(const sf::Vector2f& pos = sf::Vector2f(0,0),
                             const sf::Vector2f& p_scale = sf::Vector2f(1,1),
                             const float& p_rotation = 0):
                                 rotation(p_rotation),
                                 position(pos),
                                 scale(p_scale)
                                 {

                                 }

        float rotation;
        sf::Vector2f position, scale;

};


#endif
