#include "interface.h"
#include "../game_graph/plateau.h"
#include "../game_log/plateau.h"
#include "jeu.h"
#include "../game_log/des.h"
#include "../game_log/joueur.h"
#include "../game_log/case/casepropriete/casepropriete.h"
#include "../game_log/case/casepropriete/caseterrain.h"
#include "../graphics/graphicalengine.h"
#include "../game_log/carte/carte.h"
#include "../game_log/carte/paquet.h"
#include "../game_log/carte/payer_ou_tirer.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include "messagebox.h"

Interface::Interface(Jeu* jeu, PlateauGraph* plateau):m_jeu(jeu), m_plateau(plateau), m_lancer(true),
m_hypothequer(false),
m_deshypothequer(false),
m_construir(false)
{
    m_engine = GraphicalEngine::GetInstance();
	m_sceneNode = m_engine->GetGuiManager()->GetRootNode()->AddGuiNode();
	m_button_quitter = new GuiButtonItem;
	m_button_quitter->SetText("Quitter");
	m_button_quitter->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_quitter->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_quitter->SetData("jeu", m_jeu);
	m_button_quitter->SetCallBack("clicked", Interface::quitter);

	int x, y;
    x = m_engine->GetRenderWindow()->getSize().x-(m_button_quitter->GetSize().x+5);
    y = m_engine->GetRenderWindow()->getSize().y-(m_button_quitter->GetSize().y+5);
	m_button_quitter->SetRelativePosition(x, y);
	m_sceneNode->AddItem(m_button_quitter);

	m_button_des = new GuiButtonItem;
	m_button_des->SetText("Lancer");
	m_button_des->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_des->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_des->SetData("this", this);
	m_button_des->SetCallBack("clicked", Interface::lancerDes);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_des->GetSize().x+5);
    y = 0;
	m_button_des->SetRelativePosition(x, y);
	m_sceneNode->AddItem(m_button_des);

	for (int i=0; i<12; ++i)
    {
        int num = i+1;
        if (num>6)
            num -= 6;
        SceneNodeSpriteItem *item = new SceneNodeSpriteItem;
        item->SetImage("data/"+boost::lexical_cast<std::string>(num)+".jpg");

        x = ((i+1)>6)?0+item->GetSize().x:0-item->GetSize().x;
        y = 0-(item->GetSize().y/2);

        m_des[i] = m_plateau->getSceneNode()->AddSceneNode();
        m_des[i]->AddItem(item);
        m_des[i]->SetRelativePosition(x, y);
        m_des[i]->SetVisible(false);
    }

    m_button_hypothequer = new GuiButtonItem;
	m_button_hypothequer->SetText("Hypothéquer");
	m_button_hypothequer->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_hypothequer->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_hypothequer->SetData("this", this);
	m_button_hypothequer->SetCallBack("clicked", Interface::hypothequer);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_hypothequer->GetSize().x+5);
    y = 10+m_button_des->GetSize().y;
	m_button_hypothequer->SetRelativePosition(x, y);
	m_sceneNode->AddItem(m_button_hypothequer);

	m_button_deshypothequer = new GuiButtonItem;
	m_button_deshypothequer->SetText("Deshypothéquer");
	m_button_deshypothequer->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_deshypothequer->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_deshypothequer->SetData("this", this);
	m_button_deshypothequer->SetCallBack("clicked", Interface::deshypothequer);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_deshypothequer->GetSize().x+5);
    y = 15+m_button_des->GetSize().y+m_button_hypothequer->GetSize().y;
	m_button_deshypothequer->SetRelativePosition(x, y);
	m_sceneNode->AddItem(m_button_deshypothequer);

	m_button_construir = new GuiButtonItem;
	m_button_construir->SetText("Construir");
	m_button_construir->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_construir->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_construir->SetData("this", this);
	m_button_construir->SetCallBack("clicked", Interface::construction);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_construir->GetSize().x+5);
    y = 20+m_button_des->GetSize().y+m_button_hypothequer->GetSize().y+m_button_deshypothequer->GetSize().y;
	m_button_construir->SetRelativePosition(x, y);
	m_sceneNode->AddItem(m_button_construir);

	m_button_achat = new GuiButtonItem;
	m_button_achat->SetText("Acheter");
	m_button_achat->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_achat->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_achat->SetData("this", this);
	m_button_achat->SetCallBack("clicked", Interface::achat);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_achat->GetSize().x+5);
    y = 25+m_button_des->GetSize().y+m_button_hypothequer->GetSize().y+
            m_button_deshypothequer->GetSize().y+m_button_construir->GetSize().y;
	m_button_achat->SetRelativePosition(x, y);
	m_button_achat->SetVisible(false);
	m_sceneNode->AddItem(m_button_achat);
}
Interface::~Interface()
{

}
void Interface::update()
{
    m_button_achat->SetVisible(false);
    Joueur *joueur = m_plateau->getPlateau()->getJoueurTour();

    if (dynamic_cast<CasePropriete*>(joueur->estSur()) && !((CasePropriete*)(joueur->estSur()))->estAchete())
        m_button_achat->SetVisible(true);

    m_button_des->SetVisible(true);
	Carte* carte = joueur->lastCarte();
	joueur->setLastCarte(nullptr);

	if(carte && !dynamic_cast<Payer_ou_tirer*>(carte))
		new MessageBox("Carte "+carte->paquet()->nom(), carte->description());

	if (dynamic_cast<Payer_ou_tirer*>(carte))
        new MessageBox("Carte "+carte->paquet()->nom(), carte->description(), m_plateau->getPlateau(), dynamic_cast<Payer_ou_tirer*>(carte));

    if (m_hypothequer)
    {
        GuiWindowNode *window = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
        window->SetWindowTitle("Hypotéquer");
        window->SetClosable(true);
        int x=0;
        for (CasePropriete* m_case : joueur->proprietes())
        {
            if (!m_case->estEnHypotheque())
            {
                GuiButtonItem *button = new GuiButtonItem;
                button->SetText(m_case->nom());
                button->SetData("case", m_case);
                button->SetData("this", this);
                button->SetCallBack("clicked", Interface::hypothequer_propriete);
                window->GetContener()->AjouterItem(button, 0, x);
                ++x;
            }
        }
        window->CalculerTaille();
        m_hypothequer = false;
    }

    if (m_deshypothequer)
    {
        GuiWindowNode *window = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
        window->SetWindowTitle("Deshypotéquer");
        window->SetClosable(true);
        int x=0;
        for (CasePropriete* m_case : joueur->proprietes())
        {
            if (m_case->estEnHypotheque())
            {
                GuiButtonItem *button = new GuiButtonItem;
                button->SetText(m_case->nom());
                button->SetData("case", m_case);
                button->SetData("this", this);
                button->SetCallBack("clicked", Interface::deshypothequer_propriete);
                window->GetContener()->AjouterItem(button, 0, x);
                ++x;
            }
        }
        window->CalculerTaille();
        m_deshypothequer = false;
    }

    if (m_construir)
    {
        GuiWindowNode *window = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
        window->SetWindowTitle("Construir");
        window->SetClosable(true);
        int x=0;
        for (CasePropriete* m_case : joueur->proprietes())
        {
            if (m_case->peutConstruire())
            {
                GuiButtonItem *button = new GuiButtonItem;
                button->SetText(m_case->nom());
                button->SetData("case", m_case);
                button->SetData("this", this);
                button->SetCallBack("clicked", Interface::construir);
                window->GetContener()->AjouterItem(button, 0, x);
                ++x;
            }
        }
        window->CalculerTaille();
        m_construir = false;
    }
}
void Interface::lancerDes(GuiItem* g)
{
    for (int i=0; i<12; ++i)
        ((Interface*)g->GetData("this"))->m_des[i]->SetVisible(false);

    Des& des = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getDes();
	((Interface*)g->GetData("this"))->m_plateau->getPlateau()->lancerDes();

    ((Interface*)g->GetData("this"))->m_des[des.valeur(0)-1]->SetVisible(true);
    ((Interface*)g->GetData("this"))->m_des[des.valeur(1)+5]->SetVisible(true);
}
void Interface::achat(GuiItem* g)
{
    Joueur *joueur = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getJoueurTour();
    joueur->estSur()->acheter(joueur);
}
void Interface::hypothequer(GuiItem* g)
{
    ((Interface*)g->GetData("this"))->m_hypothequer = true;
}

void Interface::deshypothequer(GuiItem* g)
{
    ((Interface*)g->GetData("this"))->m_deshypothequer = true;
}

void Interface::hypothequer_propriete(GuiItem* g)
{
    ((CasePropriete*)g->GetData("case"))->hypothequer();
}

void Interface::deshypothequer_propriete(GuiItem* g)
{
    ((CasePropriete*)g->GetData("case"))->deshypothequer();
}

void Interface::construir(GuiItem* g)
{
    Joueur *joueur = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getJoueurTour();
    ((CaseTerrain*)g->GetData("case"))->acheter(joueur);
}

void Interface::construction(GuiItem* g)
{
    ((Interface*)g->GetData("this"))->m_construir = true;
}

void Interface::quitter(GuiItem* g)
{
    ((Jeu*)g->GetData("jeu"))->changeState(Jeu::state::main_menu);
}
