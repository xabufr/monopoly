#ifndef GUITEXTITEM_H
#define GUITEXTITEM_H

#include <SFML/Graphics.hpp>
#include "guiitem.h"
/// @todo Documenter
class GuiTextItem: public GuiItem
{
    public:
        GuiTextItem();
        /** @brief (one liner)
          *
          * (documentation goes here)
          */
        void ScaleChanged();
        /** @brief (one liner)
          *
          * (documentation goes here)
          */
        void RotationChanged();
        /** @brief (one liner)
          *
          * (documentation goes here)
          */
        void PositionChanged();
        /** @brief (one liner)
          *
          * (documentation goes here)
          */
        void Draw(sf::RenderWindow*);
        /** @brief (one liner)
          *
          * (documentation goes here)
          */
        void HandleEvent(const sf::Event&);

        void SetText(const sf::String&);
        void SetCharacterSize(unsigned int);
        unsigned int GetCharacterSize() const;
        float GetWidth() const;
        float GetHeigth() const;

        virtual sf::Vector2f GetSize() const;

        virtual ~GuiTextItem();

    protected:
        sf::Text m_texte;
};

#endif // GUITEXTITEM_H
