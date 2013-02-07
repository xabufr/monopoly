#ifndef TRIGO_H
#define TRIGO_H

#include <SFML/System.hpp>
#include <Box2D/Common/b2Math.h>

#define PI 3.1415928653

namespace Trigo
{
    float ToRad(float);
    float ToDeg(float);
    sf::Vector2f Translate(const float rad, const float dist, const sf::Vector2f& delta = sf::Vector2f(0,0));
    sf::Vector2f TranslateDeg(const float deg, const float dist, const sf::Vector2f& p = sf::Vector2f(0,0));
    float Angle(const sf::Vector2f &v1, const sf::Vector2f &v2=sf::Vector2f(0,0));
    float Angle(const float, const float, const float=0, const float=0);
    float Distance(const float x1, const float y1, const float x2 = 0.f, const float y2 = 0.f);
}

#endif // TRIGO_H
