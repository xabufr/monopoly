#include "jeu.h"
#include "../game_log/plateau.h"
#include "../game_log/joueur.h"
#include "../core/consolelogger.h"
#include "../graphics/graphicalengine.h"
#include <boost/lexical_cast.hpp>
#include "plateau.h"
#include "joueur.h"

Jeu::Jeu(): m_plateau(nullptr), m_plateauGraph(nullptr)
{
	m_requ_change_state = true;
	m_requ_state      = main_menu;
	Logger::SetLogger(new ConsoleLogger());
	m_engine = GraphicalEngine::GetInstance();
	m_engine->CreateRenderWindow(sf::VideoMode(800, 600, 32), "Monopoly");
	m_sceneNode = nullptr;
	m_nb_joueurs = 2;
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
		if(m_plateau&&m_plateauGraph)
			m_plateauGraph->update();
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
		case continue_play_menu:
			setupContinuePlayMenu();
			break;
		case play:
			setupPlay();
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
	bJouer->SetData("this", this);
	bJouer->SetCallBack("clicked", Jeu::menu_jouer);
	bJouer->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	bJouer->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	bQuitter->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	bQuitter->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	contener->AjouterItem(bJouer, 0, 0);
	contener->AjouterItem(bQuitter, 0, 1);
}
void Jeu::setupPlayMenu()
{
	GuiManager *gui = m_engine->GetGuiManager();
	m_sceneNode = m_engine->GetGuiManager()->GetRootNode();
	GuiContener *contener = m_sceneNode->AddContener();
	GuiSliderNumberItem *slider = new GuiSliderNumberItem;
	GuiTextItem *texteNbJoueurs = new GuiTextItem;
	texteNbJoueurs->SetText("2 joueurs");
	slider->SetRange(2,8);
	slider->SetColor(sf::Color(255,255,255));
	slider->SetFocusColor(sf::Color(255,0,0));
	slider->SetData("text", texteNbJoueurs);
	slider->SetData("this", this);
	slider->SetCallBack("value_changed", Jeu::update_nb_joueurs);
	slider->SetValue(m_nb_joueurs);
	GuiButtonItem *btnContinuer = new GuiButtonItem;
	btnContinuer->SetText("Continuer");
	btnContinuer->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	btnContinuer->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	btnContinuer->SetData("this", this);
	btnContinuer->SetCallBack("clicked", Jeu::continuer_jouer);
	contener->AjouterItem(slider, 0, 0);
	contener->AjouterItem(texteNbJoueurs, 1, 0);
	contener->AjouterItem(btnContinuer, 0, 1);
}
void Jeu::setupContinuePlayMenu()
{
	GuiManager *gui = m_engine->GetGuiManager();
	m_sceneNode = m_engine->GetGuiManager()->GetRootNode();
	GuiContener *cont = m_sceneNode->AddContener();
	for (size_t i = 0; i < m_nb_joueurs; ++i)
	{
		GuiTextInputItem *input = new GuiTextInputItem;
		input->SetText("Joueur " + boost::lexical_cast<std::string>(i+1));
		input->SetBgColor(sf::Color(128,128,128));
		input->SetMaxSize(sf::Vector2f(200, 30));
		cont->AjouterItem(input, (i%2==0) ?0:1, i/2);
		m_nomsJoueurs[i] = input;
	}
	GuiButtonItem *btnContinuer = new GuiButtonItem;
	GuiButtonItem *btnRetour = new GuiButtonItem;
	btnContinuer->SetText("Jouer !!!");
	btnContinuer->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	btnContinuer->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	btnContinuer->SetData("this", this);
	btnContinuer->SetCallBack("clicked", Jeu::start_play);
	btnRetour->SetText("Retour");
	btnRetour->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	btnRetour->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	btnRetour->SetData("this", this);
	btnRetour->SetCallBack("clicked", Jeu::menu_jouer);
	cont->AjouterItem(btnRetour, 0, (m_nb_joueurs+1)/2);
	cont->AjouterItem(btnContinuer, 1, (m_nb_joueurs+1)/2);
}
void Jeu::setupPlay()
{
	m_plateau      = new Plateau;
	m_plateauGraph = new PlateauGraph(m_plateau);
	for (size_t i = 0; i < m_nb_joueurs; ++i)
	{
		Joueur *joueur = new Joueur(m_nomsJoueurs[i]->GetText().toAnsiString());
		m_plateau->addJoueur(joueur);
		JoueurGraph stat(joueur);
        stat.stat(i);
	}
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
void Jeu::update_nb_joueurs(GuiItem* i)
{
	GuiSliderNumberItem *slider = (GuiSliderNumberItem*) i;
	GuiTextItem* text = (GuiTextItem*) i->GetData("text");
	text->SetText(boost::lexical_cast<std::string>((int)slider->GetValue())+" joueurs");
	((Jeu*)i->GetData("this"))->m_nb_joueurs = (int) slider->GetValue();
}
void Jeu::continuer_jouer(GuiItem* i)
{
	((Jeu*)i->GetData("this"))->changeState(continue_play_menu);
}
void Jeu::start_play(GuiItem *i)
{
	((Jeu*)i->GetData("this"))->changeState(play);
}
