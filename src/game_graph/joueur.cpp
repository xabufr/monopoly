#include "joueur.h"
#include "../graphics/graphicalengine.h"
#include "../game_log/joueur.h"
#include "terrain.h"
#include "../game_log/case/casepropriete/caseterrain.h"
#include "../graphics/graphicalengine.h"
#include "plateau.h"
#include <boost/lexical_cast.hpp>

JoueurGraph::JoueurGraph(Joueur* j,SceneNode *nodeparent,PlateauGraph *plateau):m_joueur(j), m_plateau(plateau)
{
    m_engine = GraphicalEngine::GetInstance();
	m_sceneNode = m_engine->GetGuiManager()->GetRootNode()->AddGuiNode();
	m_item_pion = new SceneNodeCircleShapeItem;
	m_item_pion->SetColor(m_couleur);
	m_nodepion = nodeparent->AddSceneNode();
	m_nodepion->AddItem(m_item_pion);
	m_item_pion->SetRadius(150);
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

void JoueurGraph::update()
{

	sf::Vector2f sizePion = m_item_pion->GetSize();
    int curPos = m_joueur->estSur()->id();
/*	m_item_pion->SetRelativePosition(sf::Vector2f(-270,250));

    int CooX =-270;
    int CooY =275;


    if (curPos <= 10 )
    {
        CooY -= (47 * curPos);
    }
    else if (curPos == 11)
    {
        CooY -= 47 * curPos;
        CooX -= 24;
    }
    else if (curPos <= 20)
    {
        CooY -= 47 * 11 ;
        CooX = -290;
        CooX -= 47 * (10 - curPos);
    }
    else if (curPos == 21)
    {
        CooY -= 47 * 11;
        CooX = -290;
        CooX -= 50 * (10 - curPos);
    }
    else if (curPos <= 30)
    {
        CooX = 250;
        CooY = -250;
        CooY -= 47 * (21 - curPos);
    }
    else if (curPos == 31)
    {
        CooX = 250;
        CooY = 250;
    }
    else if (curPos <= 40)
    {
        CooX = 225;
        CooY = 250;
        CooX += 47 * (31 - curPos);
    }
*/
    sf::IntRect rect;
    rect = m_plateau->caseRect(curPos);
	m_item_pion->SetRelativePosition(sf::Vector2f(rect.top - 5,rect.left + 5));
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
