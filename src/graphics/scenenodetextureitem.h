#ifndef SCENENODETEXTUREITEM_H
#define SCENENODETEXTUREITEM_H

#include "scenenodeitem.h"
#include <SFML/Graphics.hpp>
#include "texturemanager.h"
/// @todo Documenter
class SceneNodeTextureItem : public SceneNodeItem
{
    public:
        SceneNodeTextureItem();
        virtual ~SceneNodeTextureItem();
        void CreateTexture(const sf::Vector2i&);
        void CreateTexture(const sf::Image&);
        void UpdateTexture(sf::Uint8*, unsigned int, unsigned int, unsigned int, unsigned int);
        void DrawCircle(float, const sf::Color&, const sf::Vector2f&);
        void DrawCircle(float, const sf::Color&, float, float);

        const sf::Image& GetImage()const;
        virtual sf::Vector2f GetSize() const;

    protected:
        virtual void Draw(sf::RenderWindow* app);
        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();
    private:
        sf::Sprite m_spr;
        TextureId m_idTexture;
        sf::Texture *m_texture;
        sf::Image m_img;
};

#endif // SCENENODETEXTUREITEM_H
