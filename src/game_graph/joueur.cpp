#include "joueur.h"
#include "../graphics/graphicalengine.h"
#include "../game_log/joueur.h"
#include "../game_log/plateau.h"
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
	m_item_pion->SetRadius(20);
	m_item_stat_joueur = new GuiTextItem;
}
JoueurGraph::~JoueurGraph()
{

}
void JoueurGraph::stat(float pos) const
{
    m_item_stat_joueur->SetText(m_joueur->nom()+"\n"+boost::lexical_cast<std::string>(m_joueur->argent())+" €");
    m_item_stat_joueur->SetCharacterSize(12);
    m_sceneNode->AddItem(m_item_stat_joueur);

    pos = pos*(m_item_stat_joueur->GetHeigth()+4);
    m_item_stat_joueur->SetRelativePosition(0, pos);
}
void JoueurGraph::update(int nbreJoueursSurCase,int JoueurEnCours)
{
    if (m_plateau->getPlateau()->getJoueurTour() == m_joueur)
        m_item_stat_joueur->SetColor(m_couleur);
    else
        m_item_stat_joueur->SetColor(sf::Color(255, 255, 255));

    std::string text = m_joueur->nom()+"\n"+boost::lexical_cast<std::string>(m_joueur->argent())+" €";
    if (m_joueur->estEnPrison())
        text = m_joueur->nom()+"(Prison)\n"+boost::lexical_cast<std::string>(m_joueur->argent())+" €";
    m_item_stat_joueur->SetText(text);
	sf::Vector2f sizePion = m_item_pion->GetSize();

    int curPos = m_joueur->estSur()->id();
    sf::IntRect rect;
    rect = m_plateau->caseRect(curPos);

    if (m_joueur->estEnPrison() == true)
    {
        m_item_pion->SetRelativePosition(sf::Vector2f(rect.left + (JoueurEnCours * m_item_pion->GetSize().x)+ 60 + 35,rect.top + 80));
    }
    else
    {
        m_item_stat_joueur->SetText(m_joueur->nom()+"\n"+boost::lexical_cast<std::string>(m_joueur->argent())+" €");
        sf::Vector2f sizePion = m_item_pion->GetSize();
        if (JoueurEnCours > 1 && JoueurEnCours <= 4)
        {
            if ((curPos <= 10 and curPos >= 1) || (curPos >= 20 and curPos <= 30))
                m_item_pion->SetRelativePosition(sf::Vector2f(rect.left + (JoueurEnCours * m_item_pion->GetSize().x)+ 60,rect.top + 30));
            else
                m_item_pion->SetRelativePosition(sf::Vector2f(rect.left + (JoueurEnCours * m_item_pion->GetSize().x) + 30,rect.top + 60));
        }
        else if (JoueurEnCours > 4 && JoueurEnCours <= 8 )
        {
            if ((curPos <= 10 and curPos >= 1) || (curPos >= 20 and curPos <= 30))
                m_item_pion->SetRelativePosition(sf::Vector2f(rect.left + ((JoueurEnCours-4) * m_item_pion->GetSize().x) + 60,rect.top +  m_item_pion->GetSize().y + 30));
            else
                m_item_pion->SetRelativePosition(sf::Vector2f(rect.left + ((JoueurEnCours-4) * m_item_pion->GetSize().x) + 30,rect.top + m_item_pion->GetSize().y +60));
        }
        else //(nbreJoueursSurCase == 1 )
        {
            if ((curPos <= 10 and curPos >= 1) || (curPos >= 20 and curPos <= 30))
                m_item_pion->SetRelativePosition(sf::Vector2f(rect.left + 60,rect.top + 30));
            else
                m_item_pion->SetRelativePosition(sf::Vector2f(rect.left +30,rect.top + 60));
        }
    }
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
	m_item_pion->SetColor(m_couleur);
}
