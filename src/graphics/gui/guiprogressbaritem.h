#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "guiitem.h"
#include <SFML/Graphics.hpp>
/// @todo Documenter
class GuiProgressBarItem: public GuiItem
{
    public:
        GuiProgressBarItem();
        virtual ~GuiProgressBarItem();

        virtual void HandleEvent(const sf::Event&);
        virtual sf::Vector2f GetSize() const;

        void SetSize(const sf::Vector2f&);

        void SetMaximum(float max);
        void SetMinimum(float min);
        void SetRange(float, float);
        void SetValue(float);

        void SetFondColor(const sf::Color&);
        void SetValueColor(const sf::Color&);


    private:
        virtual void Draw(sf::RenderWindow *app);
        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();

        void CalculerRatio();

         float m_min, m_max, m_value, m_ratio;
         sf::Vector2f m_size;
         sf::RectangleShape m_fond, m_valueShape;
};

#endif // PROGRESSBAR_H
