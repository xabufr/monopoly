#ifndef GUIBUTTONITEM_H
#define GUIBUTTONITEM_H

#include "guiitem.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
/// @todo Documenter
class GuiButtonItem : public GuiItem
{
    public:
        GuiButtonItem();
        virtual void SetText(const sf::String&);
        virtual ~GuiButtonItem();
        virtual void HandleEvent(const sf::Event&);
        void SetNormalColor(const sf::Color&, const sf::Color&);
        void SetMouseOverColor(const sf::Color&,const sf::Color&);

        float GetWidth() const;
        float GetHeight() const;

        virtual sf::Vector2f GetSize() const;

        void SetCharacterSize(unsigned int);
        unsigned int GetCharacterSize() const;

    protected:

        virtual void Draw(sf::RenderWindow* app);
        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();

    private:
        sf::Text m_btn_txt;
        sf::RectangleShape m_btn_fond;
        sf::Color m_clr_nml_txt, m_clr_nml_fnd, m_clr_ovr_txt, m_clr_ovr_fnd;
};

#endif // GUIBUTTONITEM_H
