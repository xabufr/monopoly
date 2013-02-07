#ifndef SCENENODEITEM_H
#define SCENENODEITEM_H

#include <SFML/Graphics.hpp>
#include "positioninformations.h"
/// @todo Documenter
class SceneNodeItem
{
    friend class SceneManager;
    public:
        SceneNodeItem();
        virtual ~SceneNodeItem();


        virtual void SetParentPosition(const sf::Vector2f &pos);
        virtual void SetParentPosition(float x, float y);
        virtual void SetParentRotation(float);
        virtual void SetParentScale(const sf::Vector2f&);
        virtual void SetParentScale(float x, float y);

        virtual void SetRelativePosition(const sf::Vector2f&);
        virtual void SetRelativePosition(float x, float y);
        virtual void SetRelativeRotation(float);
        virtual void SetRelativeScale(const sf::Vector2f&);
        virtual void SetRelativeScale(float x, float y);

        virtual void SetAbsolutePosition(const sf::Vector2f&);
        virtual void SetAbsolutePosition(float x, float y);
        virtual void SetAbsoluteRotation(float);
        virtual void SetAbsoluteScale(const sf::Vector2f&);
        virtual void SetAbsoluteScale(float x, float y);

        virtual const sf::Vector2f& GetRelativePosition() const;
        virtual float GetRelativeRotation() const;
        virtual const sf::Vector2f& GetRelativeScale() const;

        virtual sf::Vector2f GetSize() const = 0;
        virtual void SetColor(const sf::Color&){};

        void Show();
        void Hide();
        void SetVisible(bool);

    protected:
        virtual void Draw(sf::RenderWindow* app)=0;
        PositionInformations m_relative, m_parent;

        virtual void PositionChanged()=0;
        virtual void RotationChanged()=0;
        virtual void ScaleChanged()=0;

        bool m_visible;
};

#endif // SCENENODEITEM_H
