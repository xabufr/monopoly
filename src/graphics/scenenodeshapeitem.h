#ifndef SCENENODESHAPEITEM_H
#define SCENENODESHAPEITEM_H
#include "scenenodeitem.h"

/// @todo Documenter
class SceneNodeShapeItem: public SceneNodeItem
{
    public:
        SceneNodeShapeItem();

        void SetSize(const sf::Vector2f&);
        void SetSize(float,float);

        void SetColor(const sf::Color&);
        const sf::Color& GetColor() const;
        void SetOutlineColor(const sf::Color&);
        void SetOutlineThickness(float);

        sf::FloatRect GetGlobalBounds() const;
        virtual sf::Vector2f GetSize() const;

        virtual ~SceneNodeShapeItem();
    protected:
        virtual void Draw(sf::RenderWindow* app);

        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();
    private:
        sf::RectangleShape m_shape;
};

#endif // SCENENODESHAPEITEM_H
