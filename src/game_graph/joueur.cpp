#include "joueur.h"
#include "../graphics/graphicalengine.h"
#include "../game_log/joueur.h"
#include <boost/lexical_cast.hpp>


JoueurGraph::JoueurGraph(Joueur* j):m_joueur(j)
{
    m_engine = GraphicalEngine::GetInstance();
	m_sceneNode = m_engine->GetGuiManager()->GetRootNode()->AddGuiNode();
}
JoueurGraph::~JoueurGraph()
{

}
void JoueurGraph::stat(float pos) const
{
    GuiTextItem *m_item_stat_joueur = new GuiTextItem;
    m_item_stat_joueur->SetText(m_joueur->nom()+"\n"+boost::lexical_cast<std::string>(m_joueur->argent())+" euros");
    m_item_stat_joueur->SetCharacterSize(12);
    m_sceneNode->AddItem(m_item_stat_joueur);

    pos = pos*(m_item_stat_joueur->GetHeigth()+4);
    m_item_stat_joueur->SetRelativePosition(0, pos);
}
const sf::Color& JoueurGraph::couleur() const
{
	return m_couleur;
}
Joueur* JoueurGraph::joueur() const
{
	return m_joueur;
}
void JoueurGraph::setCouleur(const sf::Color& c)
{
	m_couleur=c;
}
