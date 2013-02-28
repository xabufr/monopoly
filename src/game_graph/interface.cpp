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
#include "../game_log/carte/carte_libere.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include "messagebox.h"

Interface::Interface(Jeu* jeu, PlateauGraph* plateau):m_jeu(jeu), m_plateau(plateau),
m_hypothequer(false),
m_deshypothequer(false),
m_construire(false),
m_detruire(false),
m_message(nullptr)
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

	m_button_construire = new GuiButtonItem;
	m_button_construire->SetText("Construire");
	m_button_construire->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_construire->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_construire->SetData("this", this);
	m_button_construire->SetCallBack("clicked", Interface::construction);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_construire->GetSize().x+5);
    y = 20+m_button_des->GetSize().y+m_button_hypothequer->GetSize().y+m_button_deshypothequer->GetSize().y;
	m_button_construire->SetRelativePosition(x, y);
	m_sceneNode->AddItem(m_button_construire);

	m_button_detruire = new GuiButtonItem;
	m_button_detruire->SetText("Détruire");
	m_button_detruire->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_detruire->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_detruire->SetData("this", this);
	m_button_detruire->SetCallBack("clicked", Interface::destruction);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_detruire->GetSize().x+5);
    y = 25+m_button_des->GetSize().y+m_button_hypothequer->GetSize().y+
            m_button_deshypothequer->GetSize().y+m_button_construire->GetSize().y;
	m_button_detruire->SetRelativePosition(x, y);
	m_sceneNode->AddItem(m_button_detruire);

	m_button_achat = new GuiButtonItem;
	m_button_achat->SetText("Acheter");
	m_button_achat->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_achat->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_achat->SetData("this", this);
	m_button_achat->SetCallBack("clicked", Interface::achat);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_achat->GetSize().x+5);
    y = 30+m_button_des->GetSize().y+m_button_hypothequer->GetSize().y+
            m_button_deshypothequer->GetSize().y+m_button_construire->GetSize().y+
            m_button_detruire->GetSize().y;
	m_button_achat->SetRelativePosition(x, y);
	m_sceneNode->AddItem(m_button_achat);

	m_button_liberer = new GuiButtonItem;
	m_button_liberer->SetText("Liberer");
	m_button_liberer->SetNormalColor(sf::Color(255,255,255), sf::Color(0,0,0,0));
	m_button_liberer->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
	m_button_liberer->SetData("this", this);
	m_button_liberer->SetCallBack("clicked", Interface::liberer);

    x = m_engine->GetRenderWindow()->getSize().x-(m_button_liberer->GetSize().x+5);
    y = 35+m_button_des->GetSize().y+m_button_hypothequer->GetSize().y+
            m_button_deshypothequer->GetSize().y+m_button_construire->GetSize().y+
            m_button_detruire->GetSize().y+m_button_liberer->GetSize().y;
	m_button_liberer->SetRelativePosition(x, y);
	m_sceneNode->AddItem(m_button_liberer);

	m_info = new GuiTextItem;
	m_info->SetCharacterSize(12);
	m_info->SetColor(sf::Color(255,255,255,255));
	m_sceneNode->AddItem(m_info);
	m_info->SetRelativePosition(200,100);
	m_lastInfos = "Dernières infos";

	m_infoCase = new GuiTextItem;
	m_infoCase->SetCharacterSize(12);
	m_infoCase->SetColor(sf::Color(255,255,255));
	m_sceneNode->AddItem(m_infoCase);
	m_infoCase->SetRelativePosition(200, 320);

	m_window_detruire = m_window_construire = m_window_deshypothequer = m_window_hypothequer = nullptr;
}
Interface::~Interface()
{
	if(m_window_hypothequer)
		m_window_hypothequer->Remove();
	if(m_window_construire)
		m_window_construire->Remove();
	if(m_window_deshypothequer)
		m_window_deshypothequer->Remove();
	if(m_window_detruire)
		m_window_detruire->Remove();
	m_sceneNode->Remove();
}
void Interface::update()
{
    int x, y;
    x=y=0;
    m_button_achat->SetVisible(false);
    m_button_hypothequer->SetVisible(false);
    m_button_deshypothequer->SetVisible(false);
    m_button_construire->SetVisible(false);
    m_button_detruire->SetVisible(false);
    m_button_liberer->SetVisible(false);
    Joueur *joueur = m_plateau->getPlateau()->getJoueurTour();

	m_infoCase->SetText(joueur->nom()+" est sur : " + joueur->estSur()->nom()+"\n"+joueur->estSur()->description());

    if (dynamic_cast<CasePropriete*>(joueur->estSur()) && !((CasePropriete*)(joueur->estSur()))->estAchete()
        && joueur->argent() > ((CasePropriete*)(joueur->estSur()))->prixAchat())
        m_button_achat->SetVisible(true);

    if (joueur->estEnPrison() && joueur->cartesLiberte().size() != 0)
       m_button_liberer->SetVisible(true);

    for (CasePropriete *m_case : joueur->proprietes())
    {
        if (!m_case->estEnHypotheque())
            m_button_hypothequer->SetVisible(true);
        if (m_case->estEnHypotheque())
            m_button_deshypothequer->SetVisible(true);
        if (m_case->peutConstruire() && joueur->argent() > ((CasePropriete*)(joueur->estSur()))->prixAchat())
            m_button_construire->SetVisible(true);
        if (m_case->peutDetruire())
            m_button_detruire->SetVisible(true);
    }
	Carte* carte = joueur->lastCarte();
	joueur->setLastCarte(nullptr);

	if(carte && !dynamic_cast<Payer_ou_tirer*>(carte))
		m_lastInfos = joueur->nom()+":\nCarte " + carte->paquet()->nom() + "\n" + carte->description();

	if (dynamic_cast<Payer_ou_tirer*>(carte))
    {
        new MessageBox("Carte "+carte->paquet()->nom(), carte->description(), m_plateau->getPlateau(), dynamic_cast<Payer_ou_tirer*>(carte), m_button_des);
        m_button_des->SetVisible(false);
    }
    if (m_hypothequer && m_window_hypothequer)
    {
        m_window_hypothequer->ResetContener();
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
                button->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
                button->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
                m_window_hypothequer->GetContener()->AjouterItem(button, 0, x);
                ++x;
            }
        }
        m_window_hypothequer->CalculerTaille();
        x = (m_engine->GetRenderWindow()->getSize().x/2)-(m_window_hypothequer->GetContener()->GetSize().x/2);
        y = (m_engine->GetRenderWindow()->getSize().y/2)-(m_window_hypothequer->GetContener()->GetSize().y/2);
        m_window_hypothequer->SetRelativePosition(x, y);
        m_window_hypothequer->SetVisible(true);
    }
	else if(!m_window_hypothequer) 
    {
        m_window_hypothequer = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
        m_window_hypothequer->SetWindowTitle("Hypotéquer");
        m_window_hypothequer->SetClosable(true);
        m_window_hypothequer->CloseItem()->SetData("this", this);
        m_window_hypothequer->CloseItem()->SetCallBack("onClosed", Interface::closeHypotheque);
        m_window_hypothequer->SetVisible(false);
    }
    if (m_deshypothequer && m_window_deshypothequer)
    {
        m_window_deshypothequer->ResetContener();
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
                button->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
                button->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
                m_window_deshypothequer->GetContener()->AjouterItem(button, 0, x);
                ++x;
            }
        }
        m_window_deshypothequer->CalculerTaille();
        x = (m_engine->GetRenderWindow()->getSize().x/2)-(m_window_deshypothequer->GetContener()->GetSize().x/2);
        y = (m_engine->GetRenderWindow()->getSize().y/2)-(m_window_deshypothequer->GetContener()->GetSize().y/2);
        m_window_deshypothequer->SetRelativePosition(x, y);
        m_window_deshypothequer->SetVisible(true);
    }
    else if(!m_window_deshypothequer)
    {
        m_window_deshypothequer = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
        m_window_deshypothequer->SetWindowTitle("Deshypotéquer");
        m_window_deshypothequer->SetClosable(true);
        m_window_deshypothequer->CloseItem()->SetData("this", this);
        m_window_deshypothequer->CloseItem()->SetCallBack("onClosed", Interface::closeDeshypotheque);
        m_window_deshypothequer->SetVisible(false);
    }

    if (m_construire && m_window_construire)
    {
        m_window_construire->ResetContener();
        int x=0;
        for (CasePropriete* m_case : joueur->proprietes())
        {
            if (m_case->peutConstruire())
            {
                GuiButtonItem *button = new GuiButtonItem;
                button->SetText(m_case->nom());
                button->SetData("case", m_case);
                button->SetData("this", this);
                button->SetCallBack("clicked", Interface::construire);
                button->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
                button->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
                m_window_construire->GetContener()->AjouterItem(button, 0, x);
                ++x;
            }
        }
        m_window_construire->CalculerTaille();
        x = (m_engine->GetRenderWindow()->getSize().x/2)-(m_window_construire->GetContener()->GetSize().x/2);
        y = (m_engine->GetRenderWindow()->getSize().y/2)-(m_window_construire->GetContener()->GetSize().y/2);
        m_window_construire->SetRelativePosition(x, y);
        m_window_construire->SetVisible(true);
    }
    else if(!m_window_construire)
    {
        m_window_construire = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
        m_window_construire->SetWindowTitle("Construire");
        m_window_construire->SetClosable(true);
        m_window_construire->CloseItem()->SetData("this", this);
        m_window_construire->CloseItem()->SetCallBack("onClosed", Interface::closeConstruire);
        m_window_construire->SetVisible(false);
    }

    if (m_detruire && m_window_detruire)
    {
        m_window_detruire->ResetContener();
        int x=0;
        for (CasePropriete* m_case : joueur->proprietes())
        {
            if (m_case->peutDetruire())
            {
                GuiButtonItem *button = new GuiButtonItem;
                button->SetText(m_case->nom());
                button->SetData("case", m_case);
                button->SetData("this", this);
                button->SetCallBack("clicked", Interface::detruire);
                button->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
                button->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
                m_window_detruire->GetContener()->AjouterItem(button, 0, x);
                ++x;
            }
        }
        m_window_detruire->CalculerTaille();
        x = (m_engine->GetRenderWindow()->getSize().x/2)-(m_window_detruire->GetContener()->GetSize().x/2);
        y = (m_engine->GetRenderWindow()->getSize().y/2)-(m_window_detruire->GetContener()->GetSize().y/2);
        m_window_detruire->SetRelativePosition(x, y);
        m_window_detruire->SetVisible(true);
    }
    else if(!m_window_detruire)
    {
        m_window_detruire = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
        m_window_detruire->SetWindowTitle("Détruire");
        m_window_detruire->SetClosable(true);
        m_window_detruire->CloseItem()->SetData("this", this);
        m_window_detruire->CloseItem()->SetCallBack("onClosed", Interface::closeDetruire);
        m_window_detruire->SetVisible(false);
    }
	m_info->SetText(m_lastInfos);
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
    Joueur *joueur = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getJoueurTour();
}
void Interface::deshypothequer_propriete(GuiItem* g)
{
    ((CasePropriete*)g->GetData("case"))->deshypothequer();
}
void Interface::construire(GuiItem* g)
{
    Joueur *joueur = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getJoueurTour();
    ((CaseTerrain*)g->GetData("case"))->acheter(joueur);
}
void Interface::construction(GuiItem* g)
{
    ((Interface*)g->GetData("this"))->m_construire = true;
}
void Interface::detruire(GuiItem* g)
{
    Joueur *joueur = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getJoueurTour();
    ((CaseTerrain*)g->GetData("case"))->vendre(joueur);
}
void Interface::destruction(GuiItem* g)
{
    ((Interface*)g->GetData("this"))->m_detruire = true;
}
void Interface::liberer(GuiItem* g)
{
    Joueur *joueur = ((Interface*)g->GetData("this"))->m_plateau->getPlateau()->getJoueurTour();
    joueur->cartesLiberte().back()->utiliser();
}
void Interface::quitter(GuiItem* g)
{
    ((Jeu*)g->GetData("jeu"))->changeState(Jeu::state::main_menu);
}
void Interface::closeHypotheque(GuiItem* g)
{
    ((Interface*)g->GetData("this"))->m_window_hypothequer = nullptr;
    ((Interface*)g->GetData("this"))->m_hypothequer = false;
}
void Interface::closeDeshypotheque(GuiItem* g)
{
    ((Interface*)g->GetData("this"))->m_window_deshypothequer = nullptr;
    ((Interface*)g->GetData("this"))->m_deshypothequer = false;
}
void Interface::closeConstruire(GuiItem* g)
{
    ((Interface*)g->GetData("this"))->m_window_construire = nullptr;
    ((Interface*)g->GetData("this"))->m_construire = false;
}
void Interface::closeDetruire(GuiItem* g)
{
    ((Interface*)g->GetData("this"))->m_window_detruire = nullptr;
    ((Interface*)g->GetData("this"))->m_detruire = false;
}
