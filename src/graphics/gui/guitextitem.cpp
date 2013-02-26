#include "guitextitem.h"
#include "fontmanager.h"

GuiTextItem::GuiTextItem()
{
    m_texte.setFont(FontManager::GetInstance()->GetFont());
}
GuiTextItem::~GuiTextItem()
{
}
/** @brief ScaleChanged
  *
  * @todo: document this function
  */
void GuiTextItem::ScaleChanged()
{
}
/** @brief RotationChanged
  *
  * @todo: document this function
  */
void GuiTextItem::RotationChanged()
{
}
/** @brief PositionChanged
  *
  * @todo: document this function
  */
void GuiTextItem::PositionChanged()
{
    m_texte.setOrigin(-m_relative.position.x, -m_relative.position.y);
    m_texte.setPosition(m_parent.position);
    sf::Vector2f rel = -(m_relative.position*2.f) + sf::Vector2f(m_texte.getGlobalBounds().left, m_texte.getGlobalBounds().top)-m_parent.position;
    m_texte.setOrigin(rel);
}
/** @brief Draw
  *
  * @todo: document this function
  */
void GuiTextItem::Draw(sf::RenderWindow* app)
{
    if(!m_visible)
        return;
    app->draw(m_texte);
}
/** @brief HandleEvent
  *
  * @todo: document this function
  */
void GuiTextItem::HandleEvent(const sf::Event&)
{
}
void GuiTextItem::SetText(const std::string& texte)
{
	std::basic_string<sf::Uint32> tmp;
	sf::Utf8::toUtf32(texte.begin(), texte.end(), std::back_inserter(tmp));
	sf::String out = tmp;
	m_texte.setString(out);
    PositionChanged();
}
void GuiTextItem::SetCharacterSize(unsigned int taille)
{
    m_texte.setCharacterSize(taille);
    SetText(m_texte.getString());
}
unsigned int GuiTextItem::GetCharacterSize() const
{
    return m_texte.getCharacterSize();
}
float GuiTextItem::GetWidth() const
{
    return m_texte.getLocalBounds().width;
}
float GuiTextItem::GetHeigth() const
{
    return m_texte.getLocalBounds().height;
}
sf::Vector2f GuiTextItem::GetSize() const
{
    return sf::Vector2f(GetWidth(), GetHeigth());
}
void GuiTextItem::SetColor(const sf::Color& color)
{
    m_texte.setColor(color);
}
