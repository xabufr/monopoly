#include "terrain.h"
#include "../graphics/graphicalengine.h"
#include "plateau.h"
#include "../game_log/case/casepropriete/caseterrain.h"

TerrainGraph::TerrainGraph(PlateauGraph *p, CaseTerrain *t, SceneNode *pNode) :
	ProprieteGraph(p, t, pNode),
	m_terrain(t)
{
	m_nodeTerrain = pNode->AddSceneNode();
	sf::IntRect rect = m_plateau->maisonRect(t->id());
	m_nodeTerrain->SetRelativePosition(rect.left, rect.top);
	for (size_t i = 0; i < 4; ++i)
	{
		m_maisons[i] = new SceneNodeSpriteItem;
		m_maisons[i]->SetImage("data/maison.png");
		m_maisons[i]->SetVisible(true);
		m_nodeTerrain->AddItem(m_maisons[i]);
		m_maisons[i]->SetRelativePosition(sf::Vector2f(1+m_maisons[i]->GetSize().x*i, 1));
	}
	m_maisons[4] = new SceneNodeSpriteItem;
	m_maisons[4]->SetImage("data/hotel.png");
	m_maisons[4]->SetVisible(true);
	m_nodeTerrain->AddItem(m_maisons[4]);
	m_maisons[4]->SetRelativePosition(0.5*rect.width-0.5*m_maisons[4]->GetSize().x, 0);
	if((t->id()>0&&t->id()<11)||(t->id()>20&&t->id()<31)) 
	{
		m_maisons[4]->SetRelativePosition(0.5*rect.height-0.5*m_maisons[4]->GetSize().x, 0);
	}
	m_nodeTerrain->SetLevel(1);
	if(t->id()>0&&t->id()<11)
	{
		m_nodeTerrain->SetRelativePosition(rect.left+rect.width, rect.top);
		m_nodeTerrain->SetRelativeRotation(90);
	}
	else if(t->id()>20&&t->id()<31) 
	{
		m_nodeTerrain->SetRelativePosition(rect.left+rect.width, rect.top);
		m_nodeTerrain->SetRelativeRotation(90);
	}
}
TerrainGraph::~TerrainGraph()
{
	delete m_nodeTerrain;
}
void TerrainGraph::update()
{
	ProprieteGraph::update();
	if(m_terrain->maisons()<=4)
	{
		for (size_t i = 0; i < 5; ++i)
		{
			if(i+1>m_terrain->maisons())
				m_maisons[i]->SetVisible(false);
			else
				m_maisons[i]->SetVisible(true);
		}
	}
	else
	{
		for (size_t i = 0; i < 4; ++i)
		{
			m_maisons[i]->SetVisible(false);
		}
		m_maisons[4]->SetVisible(true);
	}
}
