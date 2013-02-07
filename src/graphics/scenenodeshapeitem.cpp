#include "scenenodeshapeitem.h"
#include <SFML/Graphics/ConvexShape.hpp>

SceneNodeShapeItem::SceneNodeShapeItem()
{

}

SceneNodeShapeItem::~SceneNodeShapeItem()
{
    //dtor
}

void SceneNodeShapeItem::SetSize(const sf::Vector2f& size)
{
    m_shape.setSize(size);
}
void SceneNodeShapeItem::SetSize(float x, float y)
{
    SetSize(sf::Vector2f(x,y));
}
void SceneNodeShapeItem::Draw(sf::RenderWindow *app)
{
    if(!m_visible)
        return;
    sf::Vector2f PosCam(app->getView().getCenter()-(app->getView().getSize()/2.f));
    sf::FloatRect rect(PosCam.x, PosCam.y, app->getView().getSize().x, app->getView().getSize().y);

    if(rect.intersects(m_shape.getGlobalBounds()))
        app->draw(m_shape);
}
void SceneNodeShapeItem::PositionChanged()
{
    m_shape.setOrigin(-m_relative.position.x,-m_relative.position.y);
    m_shape.setPosition(m_parent.position);
}
void SceneNodeShapeItem::RotationChanged()
{
    m_shape.setRotation(m_parent.rotation+m_relative.rotation);
}
void SceneNodeShapeItem::ScaleChanged()
{
    m_shape.setScale(m_parent.scale.x*m_relative.scale.x, m_parent.scale.y*m_relative.scale.y);
}
void SceneNodeShapeItem::SetColor(const sf::Color& col)
{
    m_shape.setFillColor(col);
}
void SceneNodeShapeItem::SetOutlineColor(const sf::Color& col)
{
    m_shape.setOutlineColor(col);
}
void SceneNodeShapeItem::SetOutlineThickness(float width)
{
    m_shape.setOutlineThickness(width);
}
sf::FloatRect SceneNodeShapeItem::GetGlobalBounds() const
{
    return m_shape.getGlobalBounds();
}
sf::Vector2f SceneNodeShapeItem::GetSize() const
{
    return sf::Vector2f(m_shape.getGlobalBounds().width, m_shape.getGlobalBounds().height);
}
const sf::Color& SceneNodeShapeItem::GetColor() const
{
    return m_shape.getFillColor();
}
