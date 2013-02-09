#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "../../../core/singleton.h"
#include <string>
#include <SFML/Graphics.hpp>

class FontManager: public Singleton<FontManager>
{
    friend class Singleton<FontManager>;
    public:
        void SetFont(const std::string&);
        sf::Font& GetFont() const;
    protected:
        FontManager();
        virtual ~FontManager();
    private:
        sf::Font* m_font;
};

#endif // FONTMANAGER_H
