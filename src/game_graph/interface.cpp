#include "interface.h"
#include "../game_log/plateau.h"
#include "jeu.h"
#include "../game_log/des.h"
#include "../graphics/graphicalengine.h"


Interface::Interface(Jeu* jeu):m_jeu(jeu)
{
    m_engine = GraphicalEngine::GetInstance();
	m_sceneNode = m_engine->GetGuiManager()->GetRootNode()->AddGuiNode();
	m_button_quitter = new GuiButtonItem;
	m_button_quitter->SetText("Quitter");
	m_button_quitter->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_quitter->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_quitter->SetData("this", this);
	m_button_quitter->SetCallBack("clicked", Interface::quitter);
	m_sceneNode->AddItem(m_button_quitter);
}

void Interface::lancerDes()
{
    Des des;
    des.lancer();
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

void Interface::quitter()
{
    m_jeu->changeState(Jeu::state::main_menu);
}
