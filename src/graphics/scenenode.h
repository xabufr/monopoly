#ifndef SCENENODE_H
#define SCENENODE_H

#include <vector>

#include "scenenodeitem.h"
#include "positioninformations.h"

class SceneManager;
/// @todo Documenter
class SceneNode
{
    public:
        SceneNode(SceneManager* mng, SceneNode* parent=0);

        SceneNode* AddSceneNode();
        SceneNode* AddSceneNode(SceneNode *newNode);

        SceneNodeItem* AddItem(SceneNodeItem *item);
        void RemoveItem(SceneNodeItem *item);

        const std::vector<SceneNode*>& GetChildSceneNodes() const;
        const std::vector<SceneNodeItem*>& GetChildItems() const;

        void Show();
        void Hide();
        void SetVisible(bool);
        bool IsVisible();

        void SetLevel(int level);
        void MoveLevel(int level);
        void SetRealLevelNotUpdate(int level);

        int GetLevel() const;
        int GetRealLevel() const;

        virtual ~SceneNode();

        void SetRelativePosition(const sf::Vector2f&);
        void SetRelativePosition(float x, float y);
        void SetRelativeRotation(float);
        void SetRelativeScale(const sf::Vector2f&);
        void SetRelativeScale(float x, float y);

        void SetAbsolutePosition(const sf::Vector2f&);
        void SetAbsolutePosition(float x, float y);
        void SetAbsoluteRotation(float);
        void SetAbsoluteScale(const sf::Vector2f&);
        void SetAbsoluteScale(float x, float y);

        const PositionInformations& GetAbsoluteInformations() const;

    protected:
        virtual void PositionChanged();
        virtual void RotationChanged();
        virtual void ScaleChanged();
        virtual void InformedParentBeforeDeletion(SceneNode*);

        SceneNode* m_parent;
        int m_level, m_levelReel; //Niveau relatif au parent
        SceneManager *m_manager;

        int CalculerLevel() const;//Niveau réel
        void UpdateLevel();

        void VisibilityChanged();

        bool m_visible;

        PositionInformations m_absolute, m_relative;

        std::vector<SceneNode*> m_childNodes;
        std::vector<SceneNodeItem*> m_childItems;
};

#endif // SCENENODE_H
