#include "fontmanager.h"
template<>
FontManager *Singleton<FontManager>::m_singleton = 0;

FontManager::FontManager()
{
    m_font = new sf::Font(sf::Font::getDefaultFont());
}

FontManager::~FontManager()
{
    //dtor
}

sf::Font& FontManager::GetFont() const
{
    return *m_font;
}

void FontManager::SetFont(const std::string& chemin)
{
    delete m_font;
    m_font = new sf::Font;
    m_font->loadFromFile(chemin);
}
