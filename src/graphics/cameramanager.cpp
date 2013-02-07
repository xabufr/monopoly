#include "cameramanager.h"
#include "../../core/logger.h"
#include "graphicalengine.h"

CameraManager::CameraManager()
{
    Logger::Log()<<"Construction du CameraManager"<<Logger::endl;
}

CameraManager::~CameraManager()
{
    Logger::Log()<<"Destrucion du CameraManager"<<Logger::endl;
    for(sf::View* i : m_listeCameras)
    {
        delete i;
    }
}
const std::vector<sf::View*>& CameraManager::GetCamerasList() const
{
    return m_listeCameras;
}
sf::View* CameraManager::AddCamera(const sf::Vector2f& center, const sf::Vector2f& taille)
{
    sf::View *cam = new sf::View;

    if(taille==sf::Vector2f(0,0))
    {
        cam->setSize(GraphicalEngine::GetInstance()->GetRenderWindow()->getSize().x,
                    GraphicalEngine::GetInstance()->GetRenderWindow()->getSize().y);
    }
    else
        cam->setSize(taille);

    cam->setCenter(center);
    m_listeCameras.push_back(cam);
    return cam;
}
void CameraManager::RemoveCamera(sf::View* cam)
{
    unsigned int taille=m_listeCameras.size();
    for(unsigned int i=0;i<taille;++i)
    {
        if(m_listeCameras[i]==cam)
        {
            delete cam;
            m_listeCameras.erase(m_listeCameras.begin()+i);
            return;
        }
    }
}
