#include "jeu.h"
#include "../game_log/plateau.h"
#include "../core/consolelogger.h"
#include "../graphics/graphicalengine.h"

Jeu::Jeu()
{
	m_requ_change_state = true;
	m_requ_state      = main_menu;
	Logger::SetLogger(new ConsoleLogger());
	m_engine = GraphicalEngine::GetInstance();
	m_engine->CreateRenderWindow(sf::VideoMode(800, 600, 32), "Monopoly");
	m_sceneNode = nullptr;
}
void Jeu::run()
{
	while(m_engine->GetRenderWindow()->isOpen())
	{
		if(m_requ_change_state)
			changeState();
		sf::Event event;
		while(m_engine->GetRenderWindow()->pollEvent(event))
		{
			m_engine->GetGuiManager()->HandleEvent(event);
			if(event.type == sf::Event::KeyReleased && event.key.code==sf::Keyboard::Escape)
				m_engine->GetRenderWindow()->close();
		}
		m_engine->DrawScene();
	}
}
void Jeu::changeState()
{
	m_requ_change_state = false;
	if(m_sceneNode)
	{
		m_sceneNode->Remove();
	}
	switch(m_requ_state)
	{
		case main_menu:
			setupMainMenu();
			break;
		case play_menu:
			setupPlayMenu();
			break;
	}
}
void Jeu::setupMainMenu()
{
	GuiManager *gui = m_engine->GetGuiManager();
	m_sceneNode = gui->GetRootNode()->AddGuiNode();
	GuiContener *contener = m_sceneNode->AddContener();
	GuiButtonItem *bQuitter = new GuiButtonItem;
	GuiButtonItem *bJouer = new GuiButtonItem;
	bQuitter->SetText("Quitter");
	bQuitter->SetData("this", this);
	bQuitter->SetCallBack("clicked", Jeu::quitter);
	bJouer->SetText("Jouer");
	bJouer->SetCallBack("clicked", Jeu::menu_jouer);
	bJouer->SetData("this", this);
	contener->AjouterItem(bJouer, 0, 0);
	contener->AjouterItem(bQuitter, 0, 1);
}
void Jeu::changeState(state s)
{
	m_requ_state        = s;
	m_requ_change_state = true;
}
void Jeu::menu_jouer(GuiItem* i)
{
	Jeu* thi = (Jeu*)i->GetData("this"); 
	thi->changeState(play_menu);
}
void Jeu::quitter(GuiItem* i)
{
	Jeu* j = (Jeu*) i->GetData("this");
	j->m_engine->GetRenderWindow()->close();
}
void Jeu::setupPlayMenu()
{

}
