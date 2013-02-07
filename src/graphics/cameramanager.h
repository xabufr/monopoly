#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <SFML/Graphics/View.hpp>
#include <vector>
/// @todo Documenter
class CameraManager
{
    public:
        CameraManager();
        virtual ~CameraManager();
        const std::vector<sf::View*>& GetCamerasList() const;
        sf::View* AddCamera(const sf::Vector2f& center=sf::Vector2f(0,0), const sf::Vector2f& taille=sf::Vector2f(0,0));
        void RemoveCamera(sf::View*);

    private:
        std::vector<sf::View*> m_listeCameras;
};

#endif // CAMERAMANAGER_H
