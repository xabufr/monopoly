#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include "../scenemanager.h"
#include "guiitem.h"
#include "guinode.h"
#include <vector>
#include <map>
/// @todo Documenter
class GuiManager: public SceneManager
{
    public:
        GuiManager();
        virtual ~GuiManager();
        GuiItem* AddItem(GuiItem*);
        virtual void Draw();
        void HandleEvent(const sf::Event&);
        GuiNode* GetRootNode();
        virtual void RemoveNode(SceneNode*);

        sf::Vector2f GetMousePosition();

        void LockEvent(GuiNode*);
        void UnlockEvent();
        bool isEventLocked() const;
        GuiNode* GetEventLockerNode() const;

        void AddToRemoveNode(GuiNode*);

        void ResetLevels();

    private:
        void CalculerCamera();
        GuiNode* m_eventLockedBy;

        std::vector<GuiNode*> m_toRemove;
        sf::View m_view;
};

#endif // GUIMANAGER_H
