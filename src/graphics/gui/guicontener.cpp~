#include "guicontener.h"
#include "guiitem.h"
#include "../../../core/logger.h"

GuiContener::GuiContener(SceneManager* mng, SceneNode* parent): GuiNode(mng, parent),
    m_maxSize(9999,9999), m_size(0,0), m_espacement(5,5)
{
}

GuiContener::~GuiContener()
{

}
void GuiContener::AjouterItem(GuiElement* item, int x, int y)
{

    if(item->GetType()==GuiElementType::TypeItem)
    {
        ((GuiItem*)item)->SetVisible(m_visible);
        GuiNode::AddItem((SceneNodeItem*)((GuiItem*)item));
    }

    else if(item->GetType()==GuiElementType::TypeContener)
    {
        ((GuiContener*)item)->SetVisible(m_visible);
        GuiNode::AddSceneNode((SceneNode*)((GuiContener*)item));
    }
    else
    {
        ((GuiNode*)item)->SetVisible(m_visible);
        GuiNode::AddSceneNode((SceneNode*)((GuiNode*)item));
    }

    if(int(m_items.size())> y)
    {
        if(int(m_items[y].size())>x)
        {
            m_items[y].insert(m_items[y].begin()+x, item);
        }
        else
        {
            m_items[y].push_back(item);
        }
    }
    else
    {
        m_items.push_back(std::deque<GuiElement*>());
        m_items.back().push_back(item);
    }
    CalculerPositions();
}
sf::Vector2f GuiContener::GetSize() const
{
    return m_size;
}
void GuiContener::SetMaxSize(const sf::Vector2f& max)
{
    m_maxSize=max;
}
const sf::Vector2f& GuiContener::GetMaxSize()
{
    return m_maxSize;
}
void GuiContener::SetEspacement(const sf::Vector2f& esp)
{
    m_espacement=esp;
}
void GuiContener::HandleEvent(const sf::Event& event)
{
    GuiNode::HandleEvent(event);
}
void GuiContener::CalculerPositions()
{
    float yMax=0, xMax, posY=0;
    m_size.x=0;
    size_t tailleY = m_items.size(), tailleX;
    for(size_t y_curr=0;y_curr<tailleY;++y_curr)
    {
        tailleX=m_items[y_curr].size();
        xMax=m_espacement.x*0.5;
        yMax=0;
        for(size_t x_curr=0;x_curr<tailleX;++x_curr)
        {
            if(m_items[y_curr][x_curr]->GetType()==GuiElementType::TypeItem)
            {
                ((GuiItem*)m_items[y_curr][x_curr])->SetRelativePosition(xMax, posY+0.5*m_espacement.y);
            }

            else if(m_items[y_curr][x_curr]->GetType()==GuiElementType::TypeContener)
            {
                ((GuiContener*)m_items[y_curr][x_curr])->SetRelativePosition(xMax, posY+0.5*m_espacement.y);
            }

            else
                ((GuiNode*)m_items[y_curr][x_curr])->SetRelativePosition(xMax, posY+0.5*m_espacement.y);
            xMax+=m_items[y_curr][x_curr]->GetSize().x+m_espacement.x;
            if(yMax<m_items[y_curr][x_curr]->GetSize().y)
                yMax=m_items[y_curr][x_curr]->GetSize().y;
            if(xMax>m_size.x)
                m_size.x=xMax;
        }
        posY+=yMax+m_espacement.y*0.5;
    }
    m_size.x-=m_espacement.x*0.5;
    m_size.y = posY+m_espacement.y*0.5;
}

GuiElementType GuiContener::GetType() const
{
    return GuiElementType::TypeContener;
}
void GuiContener::PositionChanged()
{
    SceneNode::PositionChanged();
}
