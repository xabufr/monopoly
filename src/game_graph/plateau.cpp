#include "plateau.h"
#include "../graphics/graphicalengine.h"
#include "../core/logger.h"

PlateauGraph::PlateauGraph(Plateau *p): m_plateau(p)
{
	m_engine = GraphicalEngine::GetInstance();
	m_item_plateau = new SceneNodeSpriteItem;
	m_engine->GetSceneManager()->GetRootNode()->AddItem(m_item_plateau);
	m_item_plateau->SetImage("data/plateau.jpg");
	sf::Vector2f sizePlateau = m_item_plateau->GetSize();
	m_item_plateau->SetRelativePosition(sf::Vector2f(-sizePlateau.x*0.5, -sizePlateau.y*0.5));
	m_camera = m_engine->GetCameraManager()->AddCamera();
	float ratio = m_engine->GetRenderWindow()->getSize().y/sizePlateau.y;
	m_item_plateau->SetAbsoluteScale(sf::Vector2f(ratio, ratio));
}
void PlateauGraph::update()
{
}
sf::IntRect PlateauGraph::caseRect(int id) const
{
	if((id>=1&&id<=10)||(id>=21&&id<=29))
	{

	}
	else if((id>=11&&id<=19)||(id>=31&&id<=39)) 
	{
		
	}
	else
	{

	}
	return sf::IntRect();
}
