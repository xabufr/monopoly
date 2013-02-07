#include "guirectangleitem.h"

GuiRectangleItem::GuiRectangleItem()
{
    //ctor
}

GuiRectangleItem::~GuiRectangleItem()
{
    //dtor
}
void GuiRectangleItem::SetSize(const sf::Vector2f& size)
{
    m_shape.setSize(size);
}
void GuiRectangleItem::SetSize(float x, float y)
{
    SetSize(sf::Vector2f(x,y));
}
void GuiRectangleItem::Draw(sf::RenderWindow *app)
{
    if(!m_visible)
        return;
    sf::Vector2f PosCam(app->getView().getCenter()-(app->getView().getSize()/2.f));
    sf::FloatRect rect(PosCam.x, PosCam.y, app->getView().getSize().x, app->getView().getSize().y);

    if(rect.intersects(m_shape.getGlobalBounds()))
        app->draw(m_shape);
}
void GuiRectangleItem::PositionChanged()
{
    m_shape.setOrigin(-m_relative.position.x,-m_relative.position.y);
    m_shape.setPosition(m_parent.position);
}
void GuiRectangleItem::RotationChanged()
{
    m_shape.setRotation(m_parent.rotation+m_relative.rotation);
}
void GuiRectangleItem::ScaleChanged()
{
    m_shape.setScale(m_parent.scale.x*m_relative.scale.x, m_parent.scale.y*m_relative.scale.y);
}
void GuiRectangleItem::SetColor(const sf::Color& col)
{
    m_shape.setFillColor(col);
}
void GuiRectangleItem::SetOutlineColor(const sf::Color& col)
{
    m_shape.setOutlineColor(col);
}
void GuiRectangleItem::SetOutlineThickness(float width)
{
    m_shape.setOutlineThickness(width);
}
sf::FloatRect GuiRectangleItem::GetGlobalBounds() const
{
    return m_shape.getGlobalBounds();
}
sf::Vector2f GuiRectangleItem::GetSize() const
{
    return sf::Vector2f(m_shape.getGlobalBounds().width, m_shape.getGlobalBounds().height);
}
const sf::Color& GuiRectangleItem::GetColor() const
{
    return m_shape.getFillColor();
}

void GuiRectangleItem::HandleEvent(const sf::Event&)
{

}
