#ifndef GUIITEM_H
#define GUIITEM_H

#include "../scenenodeitem.h"
#include <unordered_map>
#include "guielement.h"

class GuiItem;
typedef void (*ptr_function)(GuiItem*);
typedef void (&ref_function)(GuiItem*);
/// @todo Documenter
class GuiItem : public SceneNodeItem, public GuiElement
{
    public:
        GuiItem();
        virtual ~GuiItem();

        virtual bool HasFocus();
        virtual void HandleEvent(const sf::Event&)=0;
        virtual void SetCallBack(const std::string&, ref_function);
        virtual void Delete();
        static sf::Vector2f GetTextRealSize(const sf::Text&);
        static sf::Vector2f GetTextOriginDecalage(const sf::Text&);
        void SetData(const std::string&, void*);
        void* GetData(const std::string&);

        virtual sf::Vector2f GetSize() const = 0;

        virtual GuiElementType GetType() const;

    protected:
        virtual void Draw(sf::RenderWindow*)=0;
        virtual void CallCallBack(const std::string &);

        virtual void PositionChanged()=0;
        virtual void RotationChanged()=0;
        virtual void ScaleChanged()=0;

        bool m_focus, m_toDelete, m_mouveOver;
        std::unordered_map<std::string, ptr_function> m_callbacks;
        std::unordered_map<std::string, void*> m_callbacksData;
};

#endif // GUIITEM_H
