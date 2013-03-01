#include "jeu.h"
#include "../game_log/plateau.h"
#include "../game_log/joueur.h"
#include "../core/consolelogger.h"
#include "../graphics/graphicalengine.h"
#include <boost/lexical_cast.hpp>
#include "interface.h"
#include "plateau.h"
#include "joueur.h"
#include "messagebox.h"

Jeu::Jeu(): m_plateau(nullptr), m_plateauGraph(nullptr), m_interface(nullptr)
{
	m_requ_change_state = true;
	m_requ_state      = main_menu;
	Logger::SetLogger(new ConsoleLogger());
	m_engine = GraphicalEngine::GetInstance();
	m_engine->CreateRenderWindow(sf::VideoMode(800, 600, 32), "Monopoly", sf::Style::Titlebar | sf::Style::Close);
	m_sceneNode = nullptr;
	m_nb_joueurs = 2;
}
Jeu::~Jeu()
{
	if(m_plateauGraph)
		delete m_plateauGraph;
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
        if (m_interface)
            m_interface->update();
		m_engine->DrawScene();
	}
}
void Jeu::changeState()
{
	m_requ_change_state = false;
	if(m_sceneNode)
	{
		m_sceneNode->Remove();
		m_sceneNode = nullptr;
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
    if (m_plateauGraph)
    {
        delete m_plateauGraph;
        delete m_interface;
        m_interface = nullptr;
        m_plateauGraph = nullptr;
        m_plateau = nullptr;
    }
	m_sceneNode = m_engine->GetGuiManager()->GetRootNode()->AddGuiNode();
	m_nodeBg = m_engine->GetSceneManager()->GetRootNode()->AddSceneNode();
	m_camera = m_engine->GetCameraManager()->AddCamera();
	GuiButtonItem *bQuitter = new GuiButtonItem;
	GuiButtonItem *bJouer = new GuiButtonItem;
	SceneNodeSpriteItem *bg = new SceneNodeSpriteItem;
	bg->SetImage("data/background.jpeg");
	sf::Vector2f sizeBg = bg->GetSize();
	bg->SetRelativePosition(sf::Vector2f(-sizeBg.x*0.5, -sizeBg.y*0.5));
	m_camera = m_engine->GetCameraManager()->AddCamera();
	float ratio = m_engine->GetRenderWindow()->getSize().y/sizeBg.y;
	m_nodeBg->SetAbsoluteScale(sf::Vector2f(ratio, ratio));
	m_nodeBg->AddItem(bg);
	bQuitter->SetText("Quitter");
	bQuitter->SetData("this", this);
	bQuitter->SetCallBack("clicked", Jeu::quitter);
	bJouer->SetText("Jouer");
	bJouer->SetData("this", this);
	bJouer->SetCallBack("clicked", Jeu::menu_jouer);
	bJouer->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
	bJouer->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	bQuitter->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
	bQuitter->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));

	int x, y;

	x = m_engine->GetRenderWindow()->getSize().x - bQuitter->GetSize().x - 10;
	y = m_engine->GetRenderWindow()->getSize().y - bQuitter->GetSize().y - 10;
	bQuitter->SetRelativePosition(x, y);

	x = (m_engine->GetRenderWindow()->getSize().x/4) + (m_engine->GetRenderWindow()->getSize().x/2) - (bJouer->GetSize().x/2);
    y = (m_engine->GetRenderWindow()->getSize().y/3) - (bJouer->GetSize().y/2);
    bJouer->SetRelativePosition(x, y);

	m_sceneNode->AddItem(bJouer);
	m_sceneNode->AddItem(bQuitter);
}
void Jeu::setupPlayMenu()
{
    m_sceneNode = m_engine->GetGuiManager()->GetRootNode()->AddGuiNode();
	GuiSliderNumberItem *slider = new GuiSliderNumberItem;
	GuiTextItem *texteNbJoueurs = new GuiTextItem;
	texteNbJoueurs->SetText("2 joueurs");
	texteNbJoueurs->SetColor(sf::Color(0, 0, 0));
	slider->SetRange(2,8);
	slider->SetColor(sf::Color(255,0,0));
	slider->SetBarColor(sf::Color(0,0,0));
	slider->SetFocusColor(sf::Color(255,0,0));
	slider->SetData("text", texteNbJoueurs);
	slider->SetData("this", this);
	slider->SetCallBack("value_changed", Jeu::update_nb_joueurs);
	slider->SetValue(m_nb_joueurs);
	GuiButtonItem *btnContinuer = new GuiButtonItem;
	btnContinuer->SetText("Continuer");
	btnContinuer->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
	btnContinuer->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	btnContinuer->SetData("this", this);
	btnContinuer->SetCallBack("clicked", Jeu::continuer_jouer);
	GuiButtonItem *btnRetour = new GuiButtonItem;
	btnRetour->SetText("Retour");
	btnRetour->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
	btnRetour->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	btnRetour->SetData("this", this);
	btnRetour->SetCallBack("clicked", Jeu::menu);

	int x, y;

	x = m_engine->GetRenderWindow()->getSize().x - btnContinuer->GetSize().x - 10;
	y = m_engine->GetRenderWindow()->getSize().y - btnContinuer->GetSize().y - 10;
	btnContinuer->SetRelativePosition(x, y);

	x = 10;
	y = m_engine->GetRenderWindow()->getSize().y - btnRetour->GetSize().y - 10;
    btnRetour->SetRelativePosition(x, y);

	x = (m_engine->GetRenderWindow()->getSize().x/4) + (m_engine->GetRenderWindow()->getSize().x/2) - (slider->GetSize().x/2);
    y = (m_engine->GetRenderWindow()->getSize().y/3) - (slider->GetSize().y/2);
    slider->SetRelativePosition(x, y);

    x = (slider->GetRelativePosition().x+slider->GetSize().x) + 5;
    y = (m_engine->GetRenderWindow()->getSize().y/3) - (texteNbJoueurs->GetSize().y/2);
    texteNbJoueurs->SetRelativePosition(x, y);

	m_sceneNode->AddItem(slider);
	m_sceneNode->AddItem(texteNbJoueurs);
	m_sceneNode->AddItem(btnContinuer);
	m_sceneNode->AddItem(btnRetour);
}
void Jeu::setupContinuePlayMenu()
{
	m_sceneNode = m_engine->GetGuiManager()->GetRootNode()->AddGuiNode();
	GuiContener *cont = m_sceneNode->AddContener();
	cont->SetEspacement(sf::Vector2f(10, 30));
	for (size_t i = 0; i < m_nb_joueurs; ++i)
	{
		GuiTextInputItem *input = new GuiTextInputItem;
		input->SetText("Joueur " + boost::lexical_cast<std::string>(i+1));
		input->SetBgColor(sf::Color(128,128,128));
		input->SetMaxSize(sf::Vector2f(160, 30));
		cont->AjouterItem(input, (i%2==0) ?0:1, i/2);
		m_nomsJoueurs[i] = input;
	}
	GuiButtonItem *btnContinuer = new GuiButtonItem;
	GuiButtonItem *btnRetour = new GuiButtonItem;
	btnContinuer->SetText("Jouer");
	btnContinuer->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
	btnContinuer->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	btnContinuer->SetData("this", this);
	btnContinuer->SetCallBack("clicked", Jeu::start_play);
	btnRetour->SetText("Retour");
	btnRetour->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
	btnRetour->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	btnRetour->SetData("this", this);
	btnRetour->SetCallBack("clicked", Jeu::menu_jouer);

	int x, y;

	x = m_engine->GetRenderWindow()->getSize().x - btnContinuer->GetSize().x - 10;
	y = m_engine->GetRenderWindow()->getSize().y - btnContinuer->GetSize().y - 10;
	btnContinuer->SetRelativePosition(x, y);

	x = 10;
	y = m_engine->GetRenderWindow()->getSize().y - btnRetour->GetSize().y - 10;
    btnRetour->SetRelativePosition(x, y);

    x = (m_engine->GetRenderWindow()->getSize().x/2) + (m_engine->GetRenderWindow()->getSize().x/14);
    y = (m_engine->GetRenderWindow()->getSize().y/6);
    cont->SetRelativePosition(x, y);

	m_sceneNode->AddItem(btnRetour);
	m_sceneNode->AddItem(btnContinuer);
}
void Jeu::setupPlay()
{
	m_plateau      = new Plateau;
	m_plateauGraph = new PlateauGraph(m_plateau);
	m_interface = new Interface(this, m_plateauGraph);
	m_nodeBg->RemoveAllItems();
	sf::Color couleurs[8] = {
		sf::Color(255,0,0),
		sf::Color(0,255,0),
		sf::Color(0,0,255),
		sf::Color(0,255,255),
		sf::Color(255,255,0),
		sf::Color(255, 0, 255),
		sf::Color(128, 128, 255),
		sf::Color(255,128,128)
	};
	for (size_t i = 0; i < m_nb_joueurs; ++i)
	{
		Joueur *joueur = new Joueur(m_nomsJoueurs[i]->GetText().toAnsiString());
		m_plateau->addJoueur(joueur);
		m_joueurGraph[i] = new JoueurGraph(joueur,m_plateauGraph->getSceneNode(),m_plateauGraph);
        m_joueurGraph[i]->stat(i);
		m_plateauGraph->addJoueurGraph(m_joueurGraph[i]);
		m_joueurGraph[i]->setCouleur(couleurs[i]);
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
void Jeu::menu(GuiItem* i)
{
	Jeu* thi = (Jeu*)i->GetData("this");
	thi->changeState(main_menu);
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
