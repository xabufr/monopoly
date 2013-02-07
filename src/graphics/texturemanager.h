#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <unordered_map>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "../../core/singleton.h"

typedef sf::Uint32 TextureId;
class TextureManager: public Singleton<TextureManager>
{
    friend class Singleton<TextureManager>;
    public:
        /// @todo Documenter

        const sf::Texture& Get(std::string);
        TextureId Create();
        sf::Texture* GetFromId(TextureId id);
        void DeleteTextureFromId(TextureId id);
    protected:
        TextureManager();
        virtual ~TextureManager();
    private:

        std::unordered_map<std::string, sf::Texture*> m_storedUniqueTextures;
        std::unordered_map<TextureId, sf::Texture*> m_specialTextures;

        TextureId m_lastId;
};

#endif // TEXTUREMANAGER_H
