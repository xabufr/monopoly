#ifndef GRAPHICALENGINE_H
#define GRAPHICALENGINE_H

#include "../../core/singleton.h"
#include <vector>
#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "scenenodetextureitem.h"
#include "scenenodespriteitem.h"
#include "scenenodeshapeitem.h"
#include "scenenodecircleshapeitem.h"
#include "scenenodeitem.h"
#include "scenenode.h"
#include "scenemanager.h"
#include "cameramanager.h"

#include "gui/guimanager.h"
#include "gui/guinode.h"
#include "gui/guiitem.h"
#include "gui/guibuttonitem.h"
#include "gui/guiwindownode.h"
#include "gui/guitextitem.h"
#include "gui/guiprogressbaritem.h"
#include "gui/guicontener.h"
#include "gui/guiwindowcontener.h"
#include "gui/guitextinputitem.h"
#include "gui/guislidernumberitem.h"
#include "gui/guicolorselector.h"
#include "gui/guirectangleitem.h"
#include "particlemanager.h"
#include "gui/fontmanager.h"

/// @todo Documenter
class GraphicalEngine : public Singleton<GraphicalEngine>
{
    friend class Singleton<GraphicalEngine>;
    public:
        sf::RenderWindow* CreateRenderWindow(sf::VideoMode mode, const std::string &title, sf::Uint32 style=sf::Style::Default, const sf::ContextSettings &settings=sf::ContextSettings());
        sf::RenderWindow* GetRenderWindow();
        SceneManager* GetSceneManager() const;
        GuiManager* GetGuiManager() const;
        CameraManager* GetCameraManager() const;
        void DrawScene();
        float GetFramerate();
        void SetFramerateCaptureTime(int);

    protected:
        GraphicalEngine();
        ~GraphicalEngine();

    private:
        SceneManager *m_sceneManager;
        GuiManager *m_guiManager;

        sf::RenderWindow *m_app;

        /*Cameras*/
        CameraManager *m_cameraManager;
        const std::vector<sf::View*>* m_listeViews;

        /*Gestion du Framerate*/
        int m_nbFrames;
        unsigned int m_tempFramerate;
        float m_framerate;
        sf::Clock m_timerFramerate;
};

#endif // GRAPHICALENGINE_H
