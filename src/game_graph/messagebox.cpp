#include "messagebox.h"
#include "../graphics/graphicalengine.h"
#include "../game_log/carte/payer_ou_tirer.h"
#include "../game_log/carte/carte.h"
#include "../game_log/carte/paquet.h"
#include "../game_log/plateau.h"
#include "../game_log/joueur.h"

MessageBox::MessageBox(const std::string& title, const std::string& description, Plateau *plateau, Payer_ou_tirer *carte, GuiButtonItem *bouton):
    m_plateau(plateau),
    m_carte(carte),
    m_button_des_interface(bouton)
{
    m_engine = GraphicalEngine::GetInstance();
    m_window = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
    m_window->SetWindowTitle(title);
    m_window->SetClosable(false);

    GuiTextItem *item = new GuiTextItem;
    item->SetText(description);
    m_window->GetContener()->AjouterItem(item, 0, 0);
    m_window->CalculerTaille();
    int x, y;

    if (m_plateau && m_carte && m_button_des_interface)
    {
        GuiButtonItem *button = new GuiButtonItem;
        button->SetText("Payer");
        button->SetData("this", this);

        button->SetCallBack("clicked", MessageBox::payer);
        button->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
        button->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
        m_window->GetContener()->AjouterItem(button, 1, 1);
        m_window->CalculerTaille();

        button = new GuiButtonItem;
        button->SetText("Tirer");
        button->SetData("this", this);
        button->SetCallBack("clicked", MessageBox::tirer);
        button->SetNormalColor(sf::Color(0,0,0), sf::Color(0,0,0,0));
        button->SetMouseOverColor(sf::Color(255,0,0), sf::Color(0,0,0,0));
        m_window->GetContener()->AjouterItem(button, 1, 1);
        m_window->CalculerTaille();
        x = (m_engine->GetRenderWindow()->getSize().x/2)-(m_window->GetContener()->GetSize().x/2);
        y = (m_engine->GetRenderWindow()->getSize().y/2)-(m_window->GetContener()->GetSize().y/2);
        m_window->SetRelativePosition(x, y);
    }
}

void MessageBox::payer(GuiItem* g)
{
    Payer_ou_tirer *carte = ((MessageBox*)g->GetData("this"))->m_carte;
    Joueur *joueur = ((MessageBox*)g->GetData("this"))->m_plateau->getJoueurTour();
    carte->tirer(joueur);
    ((MessageBox*)g->GetData("this"))->m_button_des_interface->SetVisible(true);
    ((MessageBox*)g->GetData("this"))->m_window->Remove();
}

void MessageBox::tirer(GuiItem* g)
{
    Payer_ou_tirer *carte = ((MessageBox*)g->GetData("this"))->m_carte;
    Joueur *joueur = ((MessageBox*)g->GetData("this"))->m_plateau->getJoueurTour();
    Carte *new_carte = carte->paquetAutre()->tirer();
    joueur->setLastCarte(new_carte);
    if (!dynamic_cast<Payer_ou_tirer*>(new_carte))
		new_carte->tirer(joueur);
    ((MessageBox*)g->GetData("this"))->m_button_des_interface->SetVisible(true);
    ((MessageBox*)g->GetData("this"))->m_window->Remove();
}
