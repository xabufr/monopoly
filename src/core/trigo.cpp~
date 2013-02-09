#include "trigo.h"

namespace Trigo
{

    float ToRad(float deg)
    {
        return deg*PI/180;
    }

    float ToDeg(float rad)
    {
        return rad*180/PI;
    }

    sf::Vector2f Translate(const float rad, const float dist, const sf::Vector2f& p)
    {
        return sf::Vector2f(p.x + dist* std::cos(rad), p.y - dist * std::sin(rad));
    }
    sf::Vector2f TranslateDeg(const float deg, const float dist, const sf::Vector2f& p)
    {
        return Translate(ToRad(deg), dist, p);
    }
    float Angle(const float x1, const float y1, const float x2, const float y2)
    {
        float x = x1 - x2;
        float y = y1 - y2;

        if (y == 0.f)
        {
            if (x >= 0.f)
                return 270.f;
            else
                return 90.f;
        }

        if (x >= 0.f)
        {
            return ( ToDeg( -std::atan(y/x) ) + 270.f );
        }
        else
        {
            return ( ToDeg( -std::atan(y/x) ) + 90.f );
        }
    }
    float Angle(const sf::Vector2f &v1, const sf::Vector2f &v2)
    {
        return Angle(v1.x, v1.y, v2.x, v2.y);
    }
    float Distance(const float x1, const float y1, const float x2, const float y2)
    {
        return (std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    }
}
