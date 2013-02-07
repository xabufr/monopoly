#include "graphicalengine.h"
#include "../../core/logger.h"
#include "scenemanager.h"
#include "texturemanager.h"

template<>
GraphicalEngine *Singleton<GraphicalEngine>::m_singleton = 0;

GraphicalEngine::GraphicalEngine()
{
    Logger::Log()<<"Initialisation du moteur graphique" << Logger::endl;

    m_cameraManager = new CameraManager;
    m_sceneManager = new SceneManager;
    m_guiManager = new GuiManager;

    m_listeViews = &m_cameraManager->GetCamerasList();

    m_app = 0;

    m_tempFramerate=1000;
}

sf::RenderWindow* GraphicalEngine::CreateRenderWindow(sf::VideoMode mode, const std::string &title, sf::Uint32 style, const sf::ContextSettings &settings)
{
    m_app = new sf::RenderWindow(mode, title, style, settings);
    m_app->setFramerateLimit(60);
    m_framerate=0.f;
    m_timerFramerate.restart();
    Logger::Log()<<"Création d'une fenêtre de rendu"<<Logger::endl;
    return m_app;
}
sf::RenderWindow* GraphicalEngine::GetRenderWindow()
{
    return m_app;
}
GraphicalEngine::~GraphicalEngine()
{
    delete m_cameraManager;
    delete m_sceneManager;
    delete m_guiManager;

    TextureManager::Kill();
    Logger::Log()<<"Destruction moteur graphique" << Logger::endl;
    if(m_app)
        delete m_app;
}
SceneManager* GraphicalEngine::GetSceneManager() const
{
    return m_sceneManager;
}
CameraManager* GraphicalEngine::GetCameraManager() const
{
    return m_cameraManager;
}
void GraphicalEngine::DrawScene()
{
    m_app->clear();

    /*if(m_listeViews->size()==0)
    {
        sf::View* nCam = m_cameraManager->AddCamera();
        nCam->SetSize(m_app->GetWidth(), m_app->GetHeight());
        nCam->SetViewport(sf::FloatRect(0,0,1,1));
        nCam->SetCenter(nCam->GetSize()/2.f);
    }*/
    m_sceneManager->GetParticleManager()->Update();
    for(sf::View *view: *m_listeViews )
    {
        m_app->setView(*view);
        m_sceneManager->Draw();
    }
    m_app->setView(m_app->getDefaultView());
    m_guiManager->Draw();
    m_app->display();
    if(m_timerFramerate.getElapsedTime().asMilliseconds()>int(m_tempFramerate))
    {
        m_framerate=(float(m_nbFrames)*1000.f)/float(m_tempFramerate);
        m_nbFrames=0;
        m_timerFramerate.restart();
        //Logger::Log()<<m_framerate<<Logger::endl;
    }
    ++m_nbFrames;
}
void GraphicalEngine::SetFramerateCaptureTime(int temp)
{
    m_tempFramerate = temp;
}
float GraphicalEngine::GetFramerate()
{
    return m_framerate;
}
GuiManager* GraphicalEngine::GetGuiManager() const
{
    return m_guiManager;
}
