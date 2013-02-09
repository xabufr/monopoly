#include "texturemanager.h"
#include "../../core/logger.h"

template<>
TextureManager* Singleton<TextureManager>::m_singleton=NULL;
TextureManager::TextureManager()
{
    Logger::Log()<<"Création du TextureManager"<<Logger::endl;
    m_lastId = 0;
}

TextureManager::~TextureManager()
{
    Logger::Log()<<"Destruction du TextureManager"<<Logger::endl;
    for(auto i : m_storedUniqueTextures)
    {
        delete i.second;
    }
    for(auto i : m_specialTextures)
    {
        delete i.second;
    }
}
const sf::Texture& TextureManager::Get(std::string chemin)
{
    std::unordered_map<std::string, sf::Texture*>::iterator it;
    it=m_storedUniqueTextures.find(chemin);
    if(it!=m_storedUniqueTextures.end())
    {
        return *(it->second);
    }
    Logger::Log()<<"Chargement de l'image: '" << chemin << "'"<<Logger::endl;
    sf::Texture* tex = new sf::Texture;
    tex->loadFromFile(chemin);
    m_storedUniqueTextures[chemin]=tex;
    return *tex;
}
TextureId TextureManager::Create()
{
    sf::Texture *tex = new sf::Texture;
    m_specialTextures[m_lastId] = tex;
    return m_lastId++;
}
sf::Texture* TextureManager::GetFromId(TextureId id)
{
    return m_specialTextures[id];
}

void TextureManager::DeleteTextureFromId(TextureId id)
{
    std::unordered_map<TextureId, sf::Texture*>::iterator it;
    it = m_specialTextures.find(id);
    if(it!=m_specialTextures.end())
    {
        delete it->second;
        m_specialTextures.erase(it);
    }
}
