#include "guitextinputitem.h"
#include "../graphicalengine.h"
#include "../../../core/logger.h"

GuiTextInputItem::GuiTextInputItem(): GuiItem(), m_maxSize(100,30)
{
    m_fond.setSize(m_maxSize);
    m_pos.setSize(sf::Vector2f(2,30));
    m_maxCharacters=255;
    m_text.setFont(FontManager::GetInstance()->GetFont());
}

GuiTextInputItem::~GuiTextInputItem()
{
    //dtor
}
void GuiTextInputItem::HandleEvent(const sf::Event& event)
{
    if(!m_visible)
        return;
    if(m_focus)
    {
        if(event.type == sf::Event::TextEntered)
        {
            if(event.text.unicode!=13&&event.text.unicode!=8&&m_maxCharacters>m_string.getSize())
            {
                m_string+=event.text.unicode;
                CallCallBack("text_changed");
            }
            else if(event.text.unicode==8&&m_string.getSize()!=0)
                m_string.erase(m_string.getSize()-1);
            else if(event.text.unicode==13)
            {
                m_focus=false;
                CallCallBack("focus_out");
            }

        }
    }
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(m_fond.getGlobalBounds().contains(GraphicalEngine::GetInstance()->GetGuiManager()->GetMousePosition()))
        {
            if(!m_focus)
            {
                CallCallBack("focus_in");
                m_timer.restart();
            }
            m_focus=true;
        }
        else
        {
            if(m_focus)
                CallCallBack("focus_out");
            m_focus=false;
        }
    }
}
sf::String GuiTextInputItem::GetText() const
{
    return m_string;
}
void GuiTextInputItem::SetText(const sf::String& txt)
{
    m_string=txt;
}
void GuiTextInputItem::SetMaxSize(const sf::Vector2f& size)
{
    m_maxSize=size;
    m_fond.setSize(size);
    m_pos.setSize(sf::Vector2f(2,size.y));
}
void GuiTextInputItem::SetCharacterSize(unsigned int taille)
{
    m_text.setCharacterSize(taille);
}
void GuiTextInputItem::Draw(sf::RenderWindow* app)
{
    if(!m_visible)
        return;
    m_CalculerTexte();
    app->draw(m_fond);
    app->draw(m_text);
    if(m_focus&&m_timer.getElapsedTime().asMilliseconds()>500)
    {
        app->draw(m_pos);
        if(m_timer.getElapsedTime().asMilliseconds()>1000)
            m_timer.restart();
    }
}
void GuiTextInputItem::PositionChanged()
{
    m_text.setOrigin(-m_relative.position.x, -m_relative.position.y);
    m_text.setPosition(m_parent.position);
    //Correction d'un de SFML2 qui décalle le texte
    sf::Vector2f rel = -(m_relative.position*2.f) + sf::Vector2f(m_text.getGlobalBounds().left, m_text.getGlobalBounds().top+7)-m_parent.position;
    m_text.setOrigin(rel);

    m_fond.setOrigin(-m_relative.position.x, -m_relative.position.y);
    m_pos.setOrigin(-m_relative.position.x, -m_relative.position.y);
    m_fond.setPosition(m_parent.position);
    m_pos.setPosition(m_parent.position);
}
void GuiTextInputItem::RotationChanged()
{
    m_text.setRotation(m_parent.rotation+m_relative.rotation);
    m_fond.setRotation(m_parent.rotation+m_relative.rotation);
}
void GuiTextInputItem::ScaleChanged()
{
    m_text.setScale(m_parent.scale.x*m_relative.scale.x,m_parent.scale.y*m_relative.scale.y);
    m_fond.setScale(m_parent.scale.x*m_relative.scale.x,m_parent.scale.y*m_relative.scale.y);
}
void GuiTextInputItem::m_CalculerTexte()
{
    m_text.setString(m_string);
    if(m_text.getGlobalBounds().width > m_maxSize.x)
    {
        float width;
        sf::String tmpStr;
        unsigned int currIndex;
        for(currIndex=m_string.getSize()-1, width=0;currIndex>=0&&width<m_maxSize.x;--currIndex)
        {
            tmpStr.insert(0, m_string[currIndex]);
            width = m_CalculerLargeurTexte(tmpStr);
        }
        if(width>m_maxSize.x)
            tmpStr.erase(0);
        m_text.setString(tmpStr);
    }
    m_pos.setPosition(m_text.getPosition().x+m_text.getGlobalBounds().width, m_text.getPosition().y);
}
sf::Vector2f GuiTextInputItem::GetSize() const
{
    return m_maxSize;
}
void GuiTextInputItem::SetBgColor(const sf::Color& col)
{
    m_fond.setFillColor(col);
}
void GuiTextInputItem::SetColor(const sf::Color& col)
{
    m_text.setColor(col);
}
unsigned int GuiTextInputItem::m_CalculerLargeurTexte(const sf::String & str)
{
    int width = 0;
    const sf::Font &font = sf::Font::getDefaultFont();
    for(size_t i=0, taille = str.getSize();i<taille;++i)
    {
        width+= font.getGlyph(str[i], m_text.getCharacterSize(), m_text.getStyle()&sf::Text::Bold).advance;
    }
    return width;
}
