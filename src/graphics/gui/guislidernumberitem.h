#ifndef GUISLIDERNUMBERITEM_H
#define GUISLIDERNUMBERITEM_H
#include <SFML/Graphics.hpp>
#include "guiitem.h"
/// @todo Documenter
class GuiSliderNumberItem: public GuiItem
{
    public:
        GuiSliderNumberItem();
        virtual ~GuiSliderNumberItem();

        sf::Vector2f GetSize() const;
        void SetSize(const sf::Vector2f&);

        void SetRange(float, float);
        float GetValue() const;
        void SetValue(float);

        void SetColor(const sf::Color&);
        void SetFocusColor(const sf::Color&);
        void SetBarColor(const sf::Color&);

        void HandleEvent(const sf::Event&);

    protected:
        virtual void Draw(sf::RenderWindow* app);
        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();
    private:
        float m_value, m_min, m_max;
        sf::RectangleShape m_slider, m_barre;
        sf::Color m_couleur, m_couleurFocus;
        sf::Vector2f m_posClick;
        void ValueChanged();
        void CalculerValue();
};

#endif // GUISLIDERNUMBERITEM_H
