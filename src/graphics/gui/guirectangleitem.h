#ifndef GUIRECTANGLEITEM_H
#define GUIRECTANGLEITEM_H

#include "guiitem.h"
#include "../scenenodeshapeitem.h"
/// @todo Documenter
class GuiRectangleItem: public GuiItem
{
    public:
        GuiRectangleItem();
        virtual ~GuiRectangleItem();

        virtual void HandleEvent(const sf::Event&);

        void SetSize(const sf::Vector2f&);
        void SetSize(float,float);

        void SetColor(const sf::Color&);
        const sf::Color& GetColor() const;
        void SetOutlineColor(const sf::Color&);
        void SetOutlineThickness(float);

        sf::FloatRect GetGlobalBounds() const;
        virtual sf::Vector2f GetSize() const;

    virtual void Draw(sf::RenderWindow* app);

        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();
    private:
        sf::RectangleShape m_shape;

};

#endif // GUIRECTANGLEITEM_H
