#ifndef GUIELEMENT_H
#define GUIELEMENT_H

#include <SFML/Graphics.hpp>
/// @todo Documenter
enum GuiElementType{TypeNode, TypeItem, TypeContener};
class GuiElement
{
    public:
        GuiElement();
        virtual ~GuiElement();
        virtual sf::Vector2f GetSize() const= 0;
        virtual GuiElementType GetType() const= 0;
    protected:
    private:
};

#endif // GUIELEMENT_H
