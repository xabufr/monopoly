#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "scenenode.h"
#include <map>
#include <SFML/Graphics.hpp>

class ParticleManager;
class SceneManager
{
    friend class SceneNode;
    public:
        SceneManager();
        SceneNode* GetRootNode();
        virtual ~SceneManager();
        virtual void Draw();
        virtual void RemoveNode(SceneNode*);
        ParticleManager* GetParticleManager() const;

    protected:
        virtual void ChangeNodeLevel(int,int,SceneNode*);//Appelé par les noeuds changeant de niveau
        virtual void AddNodeLevel(int, SceneNode*);
        SceneNode *m_rootSceneNode;
        ParticleManager *m_particleManager;
        std::map<int,std::vector<SceneNode*>> m_nodesLevel;
};

#endif // SCENEMANAGER_H
