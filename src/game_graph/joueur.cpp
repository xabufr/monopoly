#include "joueur.h"
#include "../graphics/graphicalengine.h"
#include "../game_log/joueur.h"
#include <boost/lexical_cast.hpp>


JoueurGraph::JoueurGraph(Joueur* j):m_joueur(j)
{
    m_engine = GraphicalEngine::GetInstance();
	m_sceneNode = m_engine->GetGuiManager()->GetRootNode()->AddGuiNode();
}

void JoueurGraph::stat(float pos) const
{
    GuiTextItem item_stat_joueur;
    item_stat_joueur.SetText(m_joueur->nom()+"\n"+boost::lexical_cast<std::string>(m_joueur->argent())+" euros");
    item_stat_joueur.SetCharacterSize(12);
    m_sceneNode->AddItem(&item_stat_joueur);

    pos = pos*(item_stat_joueur.GetHeigth()+4);
    item_stat_joueur.SetRelativePosition(0, pos);
}
