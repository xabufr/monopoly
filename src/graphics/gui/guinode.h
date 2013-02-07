#ifndef GUINODE_H
#define GUINODE_H

#include "../scenenode.h"

class GuiWindowNode;
class GuiContener;
/// @todo Documenter
class GuiNode : public SceneNode
{
    public:
        GuiNode(SceneManager* mng, SceneNode* parent=0);
        virtual ~GuiNode();
        virtual void HandleEvent(const sf::Event&);
        virtual void HandleEventRecurse(const sf::Event&);
        GuiWindowNode* AddWindow();
        GuiContener* AddContener();
        GuiNode* AddGuiNode();
        void Remove();

    protected:
        void m_RemoveMeNextDraw();
};

#endif // GUINODE_H
