#include "guinode.h"
#include "guiitem.h"
#include "guiwindownode.h"
#include "guimanager.h"
#include "guicontener.h"
#include "../../../core/logger.h"

GuiNode::GuiNode(SceneManager* mng, SceneNode* parent): SceneNode(mng,parent)
{
}
GuiNode::~GuiNode()
{
}

void GuiNode::HandleEvent(const sf::Event& event)
{
    if(!m_visible) return;
    for(SceneNodeItem* i : m_childItems)
    {
        ((GuiItem*)(i))->HandleEvent(event);
    }
}
void GuiNode::HandleEventRecurse(const sf::Event& event)
{
    GuiNode::HandleEvent(event);
    for(SceneNode* i : m_childNodes)
    {
        ((GuiNode*)(i))->HandleEvent(event);
    }
}
GuiWindowNode* GuiNode::AddWindow()
{
    GuiWindowNode *window = new GuiWindowNode(m_manager, this);
    AddSceneNode(window);
    return window;
}
GuiContener* GuiNode::AddContener()
{
    GuiContener *cont = new GuiContener(m_manager, this);
    AddSceneNode(cont);
    return cont;
}
void GuiNode::m_RemoveMeNextDraw()
{
    for(SceneNode *n : m_childNodes)
    {
        ((GuiNode*)n)->m_RemoveMeNextDraw();
    }
    ((GuiManager*)m_manager)->AddToRemoveNode(this);
}
GuiNode* GuiNode::AddGuiNode()
{
    return (GuiNode*)AddSceneNode(new GuiNode(m_manager, this));
}
void GuiNode::Remove()
{
    m_RemoveMeNextDraw();
}
