#include "guibuttonitem.h"
#include "guimanager.h"
#include "../graphicalengine.h"

GuiButtonItem::GuiButtonItem()
{
    m_btn_fond.setFillColor(sf::Color(255,0,0));
    m_clr_nml_txt=sf::Color(0,0,0);
    m_clr_nml_fnd=sf::Color(255,255,255);
    m_clr_ovr_txt=sf::Color(255,0,0);
    m_clr_ovr_fnd=sf::Color(255,255,255);
    m_btn_txt.setFont(FontManager::GetInstance()->GetFont());
}

GuiButtonItem::~GuiButtonItem()
{
    //dtor
}

void GuiButtonItem::HandleEvent(const sf::Event& event)
{
    if(!m_visible)
        return;
    if(event.type == sf::Event::MouseMoved)
    {
        if(m_btn_fond.getGlobalBounds().contains(GraphicalEngine::GetInstance()->GetGuiManager()->GetMousePosition()))
        {
            if(!m_mouveOver)
                CallCallBack("mouse_over");
            m_mouveOver=true;
        }
        else
        {
            if(m_mouveOver)
                CallCallBack("mouse_out");
            m_mouveOver=false;
        }
    }
    if(m_mouveOver&&event.type == sf::Event::MouseButtonReleased)
    {
        CallCallBack("clicked");
    }
}

void GuiButtonItem::Draw(sf::RenderWindow* app)
{
    if(!m_visible)
        return;
    if(m_mouveOver)
    {
        m_btn_fond.setFillColor(m_clr_ovr_fnd);
        m_btn_txt.setColor(m_clr_ovr_txt);
    }
    else
    {
        m_btn_fond.setFillColor(m_clr_nml_fnd);
        m_btn_txt.setColor(m_clr_nml_txt);
    }
    app->draw(m_btn_fond);
    app->draw(m_btn_txt);
}

void GuiButtonItem::PositionChanged()
{
    m_btn_txt.setOrigin(-m_relative.position.x, -m_relative.position.y);
    m_btn_txt.setPosition(m_parent.position);
    //Correction d'un de SFML2 qui décalle le texte
    sf::Vector2f rel = -(m_relative.position*2.f) + sf::Vector2f(m_btn_txt.getGlobalBounds().left, m_btn_txt.getGlobalBounds().top)-m_parent.position;
    m_btn_txt.setOrigin(rel);

    m_btn_fond.setOrigin(-m_relative.position.x, -m_relative.position.y);
    m_btn_fond.setPosition(m_parent.position);
}

void GuiButtonItem::RotationChanged()
{
    m_btn_txt.setRotation(m_relative.rotation+m_parent.rotation);
    m_btn_fond.setRotation(m_relative.rotation+m_parent.rotation);
}

void GuiButtonItem::ScaleChanged()
{
    m_btn_txt.setScale(m_parent.scale.x*m_relative.scale.x, m_parent.scale.y*m_relative.scale.y);
    m_btn_fond.setScale(m_parent.scale.x*m_relative.scale.x, m_parent.scale.y*m_relative.scale.y);
}
void GuiButtonItem::SetText(const sf::String& txt)
{
    m_btn_txt.setString(txt);
    m_btn_fond.setSize(GetTextRealSize(m_btn_txt));
    PositionChanged();
}
void GuiButtonItem::SetNormalColor(const sf::Color& txt, const sf::Color& fnd)
{
    m_clr_nml_fnd=fnd;
    m_clr_nml_txt=txt;
}

void GuiButtonItem::SetMouseOverColor(const sf::Color& txt, const sf::Color& fnd)
{
    m_clr_ovr_fnd=fnd;
    m_clr_ovr_txt=txt;
}
float GuiButtonItem::GetWidth() const
{
    return m_btn_fond.getSize().x;
}
float GuiButtonItem::GetHeight() const
{
    return m_btn_fond.getSize().y;
}
void GuiButtonItem::SetCharacterSize(unsigned int taille)
{
    m_btn_txt.setCharacterSize(taille);
    SetText(m_btn_txt.getString());
}

unsigned int GuiButtonItem::GetCharacterSize() const
{
    return m_btn_txt.getCharacterSize();
}
sf::Vector2f GuiButtonItem::GetSize() const
{
    return sf::Vector2f(GetWidth(), GetHeight());
}
