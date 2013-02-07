#include "scenenodeitem.h"

SceneNodeItem::SceneNodeItem()
{
    m_relative.rotation=0;
    m_relative.scale=sf::Vector2f(1,1);
    m_visible=true;
}

SceneNodeItem::~SceneNodeItem()
{
    //dtor
}
const sf::Vector2f& SceneNodeItem::GetRelativePosition() const
{
    return m_relative.position;
}
float SceneNodeItem::GetRelativeRotation() const
{
    return m_relative.rotation;
}
const sf::Vector2f& SceneNodeItem::GetRelativeScale() const
{
    return m_relative.scale;
}

void SceneNodeItem::SetParentPosition(const sf::Vector2f& pos)
{
    m_parent.position=pos;
    PositionChanged();
}
void SceneNodeItem::SetParentRotation(float rot)
{
    m_parent.rotation=rot;
    RotationChanged();
}
void SceneNodeItem::SetParentScale(const sf::Vector2f& scale)
{
    m_parent.scale=scale;
    ScaleChanged();
}

void SceneNodeItem::SetRelativePosition(const sf::Vector2f& pos)
{
    m_relative.position=pos;
    PositionChanged();
}
void SceneNodeItem::SetRelativeRotation(float rot)
{
    m_relative.rotation=rot;
    RotationChanged();
}
void SceneNodeItem::SetRelativeScale(const sf::Vector2f& scale)
{
    m_relative.scale=scale;
    ScaleChanged();
}
void SceneNodeItem::SetAbsolutePosition(const sf::Vector2f& pos)
{
    m_relative.position.x=pos.x-m_parent.position.x;
    m_relative.position.y=pos.y-m_parent.position.y;
    PositionChanged();
}
void SceneNodeItem::SetAbsoluteRotation(float rot)
{
    m_relative.rotation=rot-m_parent.rotation;
    RotationChanged();
}
void SceneNodeItem::SetAbsoluteScale(const sf::Vector2f& scale)
{
    m_relative.scale.x=scale.x/m_parent.scale.x;
    m_relative.scale.y=scale.y/m_parent.scale.y;
    ScaleChanged();
}

void SceneNodeItem::SetParentPosition(float x, float y)
{
    SetParentPosition(sf::Vector2f(x,y));
}
void SceneNodeItem::SetParentScale(float x, float y)
{
    SetParentScale(sf::Vector2f(x,y));
}
void SceneNodeItem::SetRelativePosition(float x, float y)
{
    SetRelativePosition(sf::Vector2f(x,y));
}
void SceneNodeItem::SetRelativeScale(float x, float y)
{
    SetRelativeScale(sf::Vector2f(x,y));
}
void SceneNodeItem::SetAbsolutePosition(float x, float y)
{
    SetAbsolutePosition(sf::Vector2f(x,y));
}
void SceneNodeItem::SetAbsoluteScale(float x, float y)
{
    SetAbsoluteScale(sf::Vector2f(x,y));
}
void SceneNodeItem::Show()
{
    SetVisible(true);
}
void SceneNodeItem::Hide()
{
    SetVisible(false);
}
void SceneNodeItem::SetVisible(bool vis)
{
    m_visible=vis;
}

