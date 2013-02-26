#include "interface.h"
#include "../game_graph/plateau.h"
#include "../game_log/plateau.h"
#include "jeu.h"
#include "../game_log/des.h"
#include "../game_log/joueur.h"
#include "../game_log/case/casepropriete/casepropriete.h"
#include "../graphics/graphicalengine.h"
#include "../game_log/carte/carte.h"
#include "../game_log/carte/paquet.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include "messagebox.h"

Interface::Interface(Jeu* jeu, PlateauGraph* plateau):m_jeu(jeu), m_plateau(plateau), m_lancer(true)
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

	m_button_tour = new GuiButtonItem;
	m_button_tour->SetText("Tour suivant");
	m_button_tour->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_tour->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_tour->SetData("this", this);
	m_button_tour->SetCallBack("clicked", Interface::tourSuivant);
	x = m_engine->GetRenderWindow()->getSize().x-(m_button_tour->GetSize().x+5);
	m_button_tour->SetRelativePosition(x, y);
	m_button_tour->SetVisible(false);
	m_sceneNode->AddItem(m_button_tour);

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

	m_button_achat = new GuiButtonItem;
	m_button_achat->SetText("Acheter");
	m_button_achat->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_achat->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_achat->SetData("this", this);
	m_button_achat->SetCallBack("clicked", Interface::achat);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_achat->GetSize().x+5);
    y = 15+m_button_des->GetSize().y+m_button_hypothequer->GetSize().y;
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

    if (m_lancer)
    {
        m_button_des->SetVisible(true);
        m_button_tour->SetVisible(false);
    }
    else
    {
        m_button_des->SetVisible(false);
        m_button_tour->SetVisible(true);
    }
	Carte* carte = joueur->lastCarte();
	joueur->setLastCarte(nullptr);
	if(carte)
	{
		new MessageBox("Carte "+carte->paquet()->nom(), carte->description());
	}
}
void Interface::lancerDes(GuiItem* g)
{
    for (int i=0; i<12; ++i)
        ((Interface*)g->GetData("this"))->m_des[i]->SetVisible(false);

    Des& des = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getDes();
    Joueur *joueur = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getJoueurTour();
    des.lancer();
    ((Interface*)g->GetData("this"))->m_lancer = false;

    joueur->setDernierLancer(des.valeur());
    ((Interface*)g->GetData("this"))->m_des[des.valeur(0)-1]->SetVisible(true);
    ((Interface*)g->GetData("this"))->m_des[des.valeur(1)+5]->SetVisible(true);

    if (joueur->estEnPrison() && des.estDouble())
        ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->liberer(joueur);

    if (!joueur->estEnPrison() && des.estDouble())
        ((Interface*)g->GetData("this"))->m_lancer = true;

    if (!joueur->estEnPrison())
        ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->avancerCurrentJoueur(des.valeur());
}
void Interface::achat(GuiItem* g)
{
    Joueur *joueur = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getJoueurTour();
    joueur->estSur()->acheter(joueur);
}
void Interface::hypothequer(GuiItem* g)
{
    Joueur *joueur = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getJoueurTour();
    GuiWindowNode *window = ((Interface*)g->GetData("this"))->m_engine->GetGuiManager()->GetRootNode()->AddWindow();
    window->SetWindowTitle("Hypotéquer");
    window->SetClosable(true);
    std::cout << joueur->proprietes().size() << std::endl;
    int x=0;
    for (CasePropriete* m_case : joueur->proprietes())
    {
        std::cout << joueur->proprietes().size() << std::endl;
        GuiButtonItem *button = new GuiButtonItem;
        button->SetText(m_case->nom());
        window->GetContener()->AjouterItem(button, 0, x);
        ++x;
    }
    window->CalculerTaille();
}
void Interface::tourSuivant(GuiItem* g)
{
    for (int i=0; i<12; ++i)
        ((Interface*)g->GetData("this"))->m_des[i]->SetVisible(false);

    ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->joueurTourFinit();
    ((Interface*)g->GetData("this"))->m_lancer = true;
}
void Interface::quitter(GuiItem* g)
{
    ((Jeu*)g->GetData("jeu"))->changeState(Jeu::state::main_menu);
}
