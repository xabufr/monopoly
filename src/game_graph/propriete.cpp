#include "propriete.h"
#include "plateau.h"
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
		m_item->SetColor(sf::Color(255,255,255,128));
		m_item->SetVisible(true);
	}
	else
		m_item->SetVisible(false);
}
