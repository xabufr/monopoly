#include "guislidernumberitem.h"
#include "../graphicalengine.h"
#include <iostream>
#include "../../../core/logger.h"

GuiSliderNumberItem::GuiSliderNumberItem()
{
    m_barre.setSize(sf::Vector2f(100,2));
    m_slider.setSize(sf::Vector2f(10,20));
    m_min = 0;
    m_max = 100;
    m_value=0;
    ValueChanged();
}

GuiSliderNumberItem::~GuiSliderNumberItem()
{
    //dtor
}
sf::Vector2f GuiSliderNumberItem::GetSize() const
{
    return sf::Vector2f(m_barre.getSize().x, m_slider.getSize().y);
}
void GuiSliderNumberItem::SetSize(const sf::Vector2f& size)
{
    m_barre.setSize(sf::Vector2f(size.x,2));
    m_slider.setSize(sf::Vector2f(m_slider.getSize().x, size.y));
}
void GuiSliderNumberItem::SetRange(float min, float max)
{
    m_min = min;
    m_max = max;
    ValueChanged();
}
float GuiSliderNumberItem::GetValue() const
{
    return m_value;
}
void GuiSliderNumberItem::SetValue(float val)
{
    m_value=val;
    ValueChanged();
}
void GuiSliderNumberItem::SetColor(const sf::Color& col)
{
    m_couleur=col;
}
void GuiSliderNumberItem::SetFocusColor(const sf::Color& col)
{
    m_couleurFocus=col;
}
void GuiSliderNumberItem::SetBarColor(const sf::Color& col)
{
    m_barre.setFillColor(col);
}
void GuiSliderNumberItem::HandleEvent(const sf::Event& event)
{
    if(!m_visible)
        return;
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(m_slider.getGlobalBounds().contains(GraphicalEngine::GetInstance()->GetGuiManager()->GetMousePosition()))
        {
            m_focus=true;
            m_posClick = GraphicalEngine::GetInstance()->GetGuiManager()->GetMousePosition() - m_slider.getPosition()+m_slider.getOrigin();
        }
    }
    if(event.type == sf::Event::MouseButtonReleased)
        m_focus=false;
    if(m_focus&&event.type == sf::Event::MouseMoved)
    {
        m_slider.setPosition(GraphicalEngine::GetInstance()->GetGuiManager()->GetMousePosition().x-m_posClick.x+m_slider.getOrigin().x, m_slider.getPosition().y);
        CalculerValue();
    }

}
void GuiSliderNumberItem::Draw(sf::RenderWindow* app)
{
    if(!m_visible)
        return;
    app->draw(m_barre);
    if(m_focus)
        m_slider.setFillColor(m_couleurFocus);
    else
        m_slider.setFillColor(m_couleur);
    app->draw(m_slider);
}
void GuiSliderNumberItem::PositionChanged()
{
    m_barre.setOrigin(-m_relative.position.x, -m_relative.position.y);
    m_slider.setOrigin(-m_relative.position.x, -m_relative.position.y);
    m_barre.setPosition(m_parent.position.x, m_parent.position.y-1+m_slider.getSize().y/2);
    ValueChanged();
}
void GuiSliderNumberItem::RotationChanged()
{
    m_barre.setRotation(m_parent.rotation+m_relative.rotation);
    m_slider.setRotation(m_parent.rotation+m_relative.rotation);
}
void GuiSliderNumberItem::ScaleChanged()
{
    m_barre.setScale(m_parent.scale.x*m_relative.scale.x, m_parent.scale.y*m_relative.scale.y);
    m_slider.setScale(m_parent.scale.x*m_relative.scale.x, m_parent.scale.y*m_relative.scale.y);
}
void GuiSliderNumberItem::ValueChanged()
{
    if(m_value>m_max)
        m_value=m_max;
    else if(m_value<m_min)
        m_value=m_min;
    float ratio = (m_value-m_min)/(m_max-m_min);
    m_slider.setPosition(m_barre.getPosition().x+m_barre.getSize().x*ratio-m_slider.getSize().x/2, m_barre.getPosition().y-m_slider.getSize().y/2);
    CallCallBack("value_changed");
}
void GuiSliderNumberItem::CalculerValue()
{
    float ratio = (m_slider.getPosition().x-m_slider.getOrigin().x+m_slider.getSize().x*0.5-(m_barre.getPosition().x-m_barre.getOrigin().x))/m_barre.getSize().x;
    m_value = ratio*(m_max-m_min)+m_min;
    ValueChanged();
}
