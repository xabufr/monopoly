#include "scenenodecircleshapeitem.h"

SceneNodeCircleShapeItem::SceneNodeCircleShapeItem()
{
    //ctor
}

SceneNodeCircleShapeItem::~SceneNodeCircleShapeItem()
{
    //dtor
}
/** @brief SetRadius
  *
  * @todo: document this function
  */
void SceneNodeCircleShapeItem::SetRadius(float rad)
{
    m_shape.setRadius(rad);
}

/** @brief SetColor
  *
  * @todo: document this function
  */
void SceneNodeCircleShapeItem::SetColor(const sf::Color& col)
{
    m_shape.setFillColor(col);
}

/** @brief SetOutlineColor
  *
  * @todo: document this function
  */
void SceneNodeCircleShapeItem::SetOutlineColor(const sf::Color& col)
{
    m_shape.setOutlineColor(col);
}

/** @brief SetOutlineThickness
  *
  * @todo: document this function
  */
void SceneNodeCircleShapeItem::SetOutlineThickness(float tick)
{
    m_shape.setOutlineThickness(tick);
}

/** @brief GetGlobalBounds
  *
  * @todo: document this function
  */
sf::FloatRect SceneNodeCircleShapeItem::GetGlobalBounds() const
{
    return m_shape.getGlobalBounds();
}

/** @brief Draw
  *
  * @todo: document this function
  */
void SceneNodeCircleShapeItem::Draw(sf::RenderWindow* app)
{
    if(!m_visible)
        return;
    app->draw(m_shape);
}

/** @brief PositionChanged
  *
  * @todo: document this function
  */
void SceneNodeCircleShapeItem::PositionChanged()
{
    m_shape.setOrigin(-m_relative.position);
    m_shape.setPosition(m_parent.position);
}

/** @brief RotationChanged
  *
  * @todo: document this function
  */
void SceneNodeCircleShapeItem::RotationChanged()
{
    m_shape.setRotation(m_parent.rotation+m_relative.rotation);
}

/** @brief ScaleChanged
  *
  * @todo: document this function
  */
void SceneNodeCircleShapeItem::ScaleChanged()
{
    m_shape.setScale(m_parent.scale.x*m_relative.scale.x, m_parent.scale.y*m_relative.scale.y);
}

sf::Vector2f SceneNodeCircleShapeItem::GetSize() const
{
    return sf::Vector2f(m_shape.getRadius()*2, m_shape.getRadius()*2);
}
