#ifndef SCENENODECIRCLESHAPEITEM_H
#define SCENENODECIRCLESHAPEITEM_H
#include "scenenodeitem.h"
#include <SFML/Graphics/CircleShape.hpp>

class SceneNodeCircleShapeItem: public SceneNodeItem
{
    public:
        SceneNodeCircleShapeItem();
        virtual ~SceneNodeCircleShapeItem();

        void SetRadius(float);

        void SetColor(const sf::Color&);
        void SetOutlineColor(const sf::Color&);
        void SetOutlineThickness(float);

        sf::FloatRect GetGlobalBounds() const;

        sf::Vector2f GetSize() const;

    protected:
        virtual void Draw(sf::RenderWindow* app);

        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();
    private:
        sf::CircleShape m_shape;
};

#endif // SCENENODECIRCLESHAPEITEM_H
