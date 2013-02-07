#ifndef GUITEXTINPUTITEM_H
#define GUITEXTINPUTITEM_H

#include "guiitem.h"
#include <SFML/Graphics.hpp>
/// @todo Documenter
class GuiTextInputItem: public GuiItem
{
    public:
        GuiTextInputItem();
        virtual ~GuiTextInputItem();

        void HandleEvent(const sf::Event&);
        sf::String GetText() const;
        void SetText(const sf::String&);
        void SetMaxSize(const sf::Vector2f&);
        void SetCharacterSize(unsigned int);
        sf::Vector2f GetSize() const;
        void SetBgColor(const sf::Color&);
        void SetColor(const sf::Color&);
    protected:
        virtual void Draw(sf::RenderWindow* app);
        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();
    private:

        void m_CalculerTexte();
        unsigned int m_CalculerLargeurTexte(const sf::String&);

        sf::Text m_text;
        sf::RectangleShape m_fond, m_pos;
        sf::Vector2f m_maxSize;
        sf::String m_string;
        sf::Clock m_timer;
        unsigned int m_maxCharacters;
};

#endif // GUITEXTINPUTITEM_H
