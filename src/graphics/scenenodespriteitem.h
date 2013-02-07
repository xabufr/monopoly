#ifndef SCENENODESPRITEITEM_H
#define SCENENODESPRITEITEM_H

#include "scenenodeitem.h"
#include "texturemanager.h"
/// @todo Documenter
class SceneNodeSpriteItem : public SceneNodeItem
{
    public:
        SceneNodeSpriteItem();
        virtual ~SceneNodeSpriteItem();
        void SetImage(const std::string&);
        void SetColor(const sf::Color&);
        virtual sf::Vector2f GetSize() const;

    protected:
        virtual void Draw(sf::RenderWindow* app);

        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();

    private:
        sf::Sprite m_spr;
        sf::Vector2f m_taille;
};

#endif // SCENENODESPRITEITEM_H
