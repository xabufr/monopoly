#include "guiwindownode.h"
#include "guiitem.h"
#include "guimanager.h"
#include <iostream>

GuiWindowNode::GuiWindowNode(SceneManager* mng, SceneNode* parent): GuiNode(mng,parent), m_closed(false)
{
    m_windowShape = new SceneNodeShapeItem;
    m_contenerShape = new SceneNodeShapeItem;
    m_windowTitle = new GuiTextItem;


    m_windowTitle->SetRelativePosition(0,0);
    m_windowTitle->SetCharacterSize(10);
    m_windowTitle->SetColor(sf::Color(0,0,0));

    AddItem(m_contenerShape);
    AddItem(m_windowShape);
    AddItem(m_windowTitle);


    m_windowShape->SetSize(100,100);
    m_windowShape->SetColor(sf::Color(207,204,201));
    m_windowShape->SetOutlineColor(sf::Color(100,100,100));
    m_windowShape->SetOutlineThickness(1.f);
    m_windowShape->SetRelativePosition(0,0);

    m_contenerShape->SetSize(0,0);
    m_contenerShape->SetColor(sf::Color(200,200,200));
    m_contenerShape->SetOutlineColor(sf::Color(100,100,100));
    m_contenerShape->SetOutlineThickness(1.f);
    m_contenerShape->SetRelativePosition(0,100);

    m_contener = new GuiWindowContener(m_manager, this);
    AddSceneNode(m_contener);
    m_contener->SetRelativePosition(0,101);

    m_moving=false;
    m_closable=false;
    m_btnClose=0;
}
GuiWindowNode::~GuiWindowNode()
{

}
void GuiWindowNode::HandleEvent(const sf::Event& event)
{
    if(!m_visible) return;
    if(m_contenerShape->GetGlobalBounds().contains(((GuiManager*)m_manager)->GetMousePosition()))
    {
        ((GuiManager*)m_manager)->LockEvent(this);
    }
    else if(((GuiManager*)m_manager)->GetEventLockerNode()==this&&m_moving==false)
    {
        ((GuiManager*)m_manager)->UnlockEvent();
    }

    if(event.type==sf::Event::MouseButtonPressed)
    {
        if(m_windowShape->GetGlobalBounds().contains(((GuiManager*)m_manager)->GetMousePosition()))
        {
            m_moving=true;
            m_posClickMoving = ((GuiManager*)m_manager)->GetMousePosition() - m_absolute.position;
            ((GuiManager*)m_manager)->LockEvent(this);
            ((GuiManager*)m_manager)->ResetLevels();
            SetLevel(1);
        }
        else if(m_contenerShape->GetGlobalBounds().contains(((GuiManager*)m_manager)->GetMousePosition()))
        {
            ((GuiManager*)m_manager)->ResetLevels();
            SetLevel(1);
        }
    }
    if(event.type==sf::Event::MouseButtonReleased)
    {
        if(m_moving)
            ((GuiManager*)m_manager)->UnlockEvent();
        m_moving=false;
    }
    if(event.type==sf::Event::MouseMoved&&m_moving)
    {
        SetAbsolutePosition(((GuiManager*)m_manager)->GetMousePosition()-m_posClickMoving);
    }
    for(SceneNodeItem* i : m_childItems)
    {
        if(i!=m_windowShape&&i!=m_contenerShape)
            ((GuiItem*)(i))->HandleEvent(event);
    }
}
void GuiWindowNode::HandleEventRecurse(const sf::Event& event)
{
    HandleEvent(event);
    for(SceneNode* i : m_childNodes)
    {
        ((GuiNode*)(i))->HandleEvent(event);
    }
}
void GuiWindowNode::SetClosable(bool clos)
{
    m_closable=clos;
    ClosableChanged();
}
bool GuiWindowNode::IsClosable() const
{
    return m_closable;
}
bool GuiWindowNode::IsClosed() const
{
    return m_closed;
}
void GuiWindowNode::ClosableChanged()
{
    if(m_closable&&!m_btnClose)
    {
        m_btnClose = new GuiButtonItem;
        m_btnClose->SetText("x");
        m_btnClose->SetData("window", (void*)this);
        m_btnClose->SetCallBack("clicked", GuiWindowNode::CloseWindowCallBack);
        m_btnClose->SetNormalColor(sf::Color(0,0,0),sf::Color(0,0,0,0));
        m_btnClose->SetMouseOverColor(sf::Color(255,0,0),sf::Color(0,0,0,0));

        this->AddItem(m_btnClose);
    }
    else if(!m_closable&&m_btnClose)
    {
        this->RemoveItem(m_btnClose);
        delete m_btnClose;
        m_btnClose=0;
    }
    CalculerCoord();
}
void GuiWindowNode::CloseWindowCallBack(GuiItem* item)
{
    ((GuiWindowNode*)item->GetData("window"))->m_RemoveMeNextDraw();
    ((GuiWindowNode*)item->GetData("window"))->m_closed = true;
}
void GuiWindowNode::SetWindowTitle(const std::string& title)
{
    m_windowTitle->SetText(title);
    CalculerCoord();
}
void GuiWindowNode::SetColorTitle(sf::Color c)
{
    m_windowTitle->SetColor(c);
}

void GuiWindowNode::SetCharacterSizeTitle(int v)
{
    m_windowTitle->SetCharacterSize(v);
}
void GuiWindowNode::SetColorShape(sf::Color c)
{
    m_windowShape->SetColor(c);
}

void GuiWindowNode::SetColorContener(sf::Color c)
{
    m_contenerShape->SetColor(c);
}
void GuiWindowNode::SetColorOutlineShape(sf::Color c)
{
    m_windowShape->SetOutlineColor(c);
}

void GuiWindowNode::SetColorOutlineContener(sf::Color c)
{
    m_contenerShape->SetOutlineColor(c);
}
void GuiWindowNode::CalculerCoord()
{
    sf::Vector2f t(m_windowTitle->GetWidth(), m_windowTitle->GetHeigth());
    if(m_closable)
    {
        t.x+=m_btnClose->GetWidth();
        t.y=(t.y<m_btnClose->GetHeight())?m_btnClose->GetHeight():t.y;
    }
    m_windowShape->SetSize(t);
    m_hauteurTitle=t.y;
    if(m_closable)
        m_btnClose->SetRelativePosition(m_windowShape->GetGlobalBounds().width-m_btnClose->GetWidth()-3, 0);
    m_contener->SetRelativePosition(0, t.y+1);
    m_contenerShape->SetRelativePosition(0, t.y+1);
}
GuiWindowContener* GuiWindowNode::GetContener() const
{
    return m_contener;
}
void GuiWindowNode::CalculerTaille()
{
    sf::Vector2f tailleContener(m_contener->GetSize());
    m_contenerShape->SetSize(tailleContener);
    if(tailleContener.x>m_windowShape->GetSize().x)
    {
        m_windowShape->SetSize(tailleContener.x, m_hauteurTitle);
        if(m_closable)
            m_btnClose->SetRelativePosition(m_windowShape->GetGlobalBounds().width-m_btnClose->GetWidth()-3, 0);
    }
    else
    {
        m_contenerShape->SetSize(m_windowShape->GetSize().x-2, m_contenerShape->GetSize().y);
    }
}
GuiItem* GuiWindowNode::CloseItem()
{
	return m_btnClose;
}
void GuiWindowNode::ResetContener()
{
	m_contener->Remove();
    m_contener = new GuiWindowContener(m_manager, this);
    AddSceneNode(m_contener);
    m_contener->SetRelativePosition(0,101);
	CalculerCoord();
}
