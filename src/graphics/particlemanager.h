#ifndef PARTICLEMANAGER_H
#define PARTICLEMANAGER_H

#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../../core/random.h"
#include <Box2D/Box2D.h>

class SceneManager;
class SceneNode;
class SceneNodeItem;
struct ParticleParameters
{
    int number;
    bool colorFromList;
    std::vector<sf::Color> colorList;
    sf::Color colorMin, colorMax;
    int level;
    int timeToLive;
    sf::Clock clock;
    float minSize, maxSize;
    sf::Vector2f position;
    float minAngle, maxAngle;
    float minPower, maxPower;
    bool changeScale, useImage;
    float rotation, gravity;
    ParticleParameters()
    {
        changeScale=false;
        useImage=false;
        scaleFin = scaleDebut=1.f;
        gravity=true;

    }
    std::string image;
    float scaleDebut, scaleFin;
};

struct Particle
{
    SceneNodeItem *item;
    int timeToLive;
    float puissance;
    sf::Clock timer, timerDep;
    sf::Vector2f dir;
    sf::Color color;
    bool gravity;
    Particle()
    {
        gravity=true;
    }
};

class ParticleManager
{
    public:
        ParticleManager(SceneManager* parent);
        virtual ~ParticleManager();

        void Update();
        SceneNode* AddParticleSystem(const ParticleParameters&);
        void Remove(SceneNode*);
        void SetWorld(b2World *world);
        void AddParticle(const ParticleParameters&);

    protected:
    private:
        static sf::Color m_RandomColor(const ParticleParameters&);
        SceneNode* m_node;
        std::unordered_map<SceneNode*, ParticleParameters> m_nodes;
        std::unordered_map<SceneNodeItem*,SceneNode*> m_nodesItems;
        std::vector<Particle> m_particles;
        SceneManager *m_parent;
        b2World *m_world;

        SceneNode* m_CreateNodeFromParameters(const ParticleParameters&);
};

#endif // PARTICLEMANAGER_H
