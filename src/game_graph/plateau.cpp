#include "plateau.h"
#include "../graphics/graphicalengine.h"
#include "../core/logger.h"

PlateauGraph::PlateauGraph(Plateau *p): m_plateau(p)
{
	m_engine = GraphicalEngine::GetInstance();
	m_item_plateau = new SceneNodeSpriteItem;
	m_engine->GetSceneManager()->GetRootNode()->AddItem(m_item_plateau);
	m_item_plateau->SetImage("data/plateau.jpg");
	m_item_plateau->SetRelativePosition(sf::Vector2f(0,0));
	m_engine->GetCameraManager()->AddCamera();
}
