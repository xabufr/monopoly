#include "scenenodespriteitem.h"
#include "../../core/singleton.h"

SceneNodeSpriteItem::SceneNodeSpriteItem()
{
}

SceneNodeSpriteItem::~SceneNodeSpriteItem()
{
    //dtor
}
void SceneNodeSpriteItem::SetImage(const std::string& chemin)
{
    m_spr.setTexture(TextureManager::GetInstance()->Get(chemin));
}
void SceneNodeSpriteItem::PositionChanged()
{
    m_spr.setOrigin(-m_relative.position.x, -m_relative.position.y);
    m_spr.setPosition(m_parent.position);
}
void SceneNodeSpriteItem::RotationChanged()
{
    m_spr.setRotation(m_relative.rotation+m_parent.rotation);
}
void SceneNodeSpriteItem::ScaleChanged()
{
    m_spr.setScale(m_parent.scale.x*m_relative.scale.x, m_parent.scale.y*m_relative.scale.y);
}
void SceneNodeSpriteItem::Draw(sf::RenderWindow* app)
{
    if(!m_visible||m_spr.getColor().a==0)
        return;
    sf::Vector2f PosCam(app->getView().getCenter()-(app->getView().getSize()/2.f));
    sf::FloatRect rect(PosCam.x, PosCam.y, app->getView().getSize().x, app->getView().getSize().y);

    if(rect.intersects(m_spr.getGlobalBounds()))
    {
        app->draw(m_spr);
    }
}
sf::Vector2f SceneNodeSpriteItem::GetSize() const
{
    return sf::Vector2f(m_spr.getTextureRect().width, m_spr.getTextureRect().height);
}
void SceneNodeSpriteItem::SetColor(const sf::Color& col)
{
    m_spr.setColor(col);
}
