#ifndef GUICONTENER_H
#define GUICONTENER_H
#include "guinode.h"
#include <SFML/Graphics.hpp>
#include <deque>
#include "guielement.h"
/// @todo Documenter
class GuiContener: public GuiNode, public GuiElement
{
    public:
        GuiContener(SceneManager* mng, SceneNode* parent);
        virtual void AjouterItem(GuiElement*, int, int);
        virtual sf::Vector2f GetSize() const;
        void SetMaxSize(const sf::Vector2f&);
        const sf::Vector2f & GetMaxSize();
        void SetEspacement(const sf::Vector2f&);
        virtual ~GuiContener();
        void HandleEvent(const sf::Event&);
        virtual GuiElementType GetType() const;

    protected:
        virtual void PositionChanged();

    private:
        void CalculerPositions();

        sf::Vector2f m_maxSize, m_size, m_espacement;
        std::deque<std::deque<GuiElement*>> m_items;
};

#endif // GUICONTENER_H
