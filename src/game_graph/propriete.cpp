#include "propriete.h"
#include "plateau.h"
#include "joueur.h"
#include "../game_log/case/casepropriete/casepropriete.h"
#include "../graphics/graphicalengine.h"

ProprieteGraph::ProprieteGraph(PlateauGraph* p, CasePropriete *c, SceneNode *parent):
m_plateau(p),
	m_case(c)
{
	m_node = parent->AddSceneNode();
	m_item = new SceneNodeShapeItem;
	m_node->AddItem(m_item);
	sf::IntRect rect = p->caseRect(c->id());
	m_item->SetSize(rect.width, rect.height);
	m_node->SetRelativePosition(rect.left, rect.top);
}
ProprieteGraph::~ProprieteGraph()
{
	delete m_node;
}
void ProprieteGraph::update()
{
	if(m_case->proprietaire())
	{
		JoueurGraph *jg = m_plateau->findJoueurGraph(m_case->proprietaire());
		sf::Color c;
		if(jg)
		{
			c = jg->couleur();
		}
		if(m_case->estEnHypotheque())
		{
			c = sf::Color(0,0,0);
		}
		c.a=128;
		m_item->SetColor(c);
		m_item->SetVisible(true);
	}
	else
		m_item->SetVisible(false);
}
