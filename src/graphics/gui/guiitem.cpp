#include "guiitem.h"

GuiItem::GuiItem()
{
    m_focus=false;
    m_toDelete=false;
    m_mouveOver=false;
}

GuiItem::~GuiItem()
{
}
bool GuiItem::HasFocus()
{
    return m_focus;
}

void GuiItem::SetCallBack(const std::string& nom, ref_function func)
{
    m_callbacks[nom] = &func;
}

void GuiItem::Delete()
{
    m_toDelete=true;
}

void GuiItem::CallCallBack(const std::string& callback)
{
    std::unordered_map<std::string, ptr_function>::iterator it;
    it = m_callbacks.find(callback);
    if(it!=m_callbacks.end())//On vérifie si la callback existe bien
    {
        (*(it->second))(this); //Appel de la callback
    }
}
sf::Vector2f GuiItem::GetTextRealSize(const sf::Text& txt)
{
    sf::Vector2f taille(0,0);

    unsigned int characterSize = txt.getCharacterSize();
    const sf::Font &font = *txt.getFont();
    const sf::String &contenu = txt.getString();
    size_t tailleContenu = contenu.getSize();

    bool bold = (txt.getStyle() & sf::Text::Bold);
    sf::Uint32 charact;
    size_t currHeight;
    for(size_t i=0;i<tailleContenu;++i)
    {
        charact=contenu[i];
        const sf::Glyph& currGlyph = font.getGlyph(charact, characterSize, bold);
        currHeight = currGlyph.bounds.height;
        if(currHeight>taille.y)
            taille.y=currHeight;
        taille.x+=currGlyph.advance;
    }

    return taille;
}
sf::Vector2f GuiItem::GetTextOriginDecalage(const sf::Text& txt)
{
    sf::Vector2f taille(txt.getLocalBounds().width-1,txt.getLocalBounds().height-1);
    return (taille-GetTextRealSize(txt));
}

void GuiItem::SetData(const std::string& key, void* data)
{
    m_callbacksData[key] = data;
}
void* GuiItem::GetData(const std::string& key)
{
    std::unordered_map<std::string, void*>::iterator it;
    it=m_callbacksData.find(key);
    if(it!=m_callbacksData.end())
        return it->second;
    return 0;
}
GuiElementType GuiItem::GetType() const
{
    return GuiElementType::TypeItem;
}
