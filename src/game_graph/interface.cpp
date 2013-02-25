#include "interface.h"
#include "../game_log/plateau.h"
#include "jeu.h"
#include "../game_log/des.h"
#include "../graphics/graphicalengine.h"
#include <iostream>

Interface::Interface(Jeu* jeu):m_jeu(jeu)
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

	for (int i=1; i<7; ++i)
    {

    }
}

Interface::~Interface()
{

}

void Interface::lancerDes(GuiItem* g)
{
    Des des;
    des.lancer();
    std::cout << des.valeur() << std::endl;
}

void Interface::achat()
{

}

void Interface::hypothequer()
{

}

void Interface::tourSuivant()
{

}

void Interface::quitter(GuiItem* g)
{
    ((Jeu*)g->GetData("jeu"))->changeState(Jeu::state::main_menu);
}
