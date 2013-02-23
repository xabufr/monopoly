#include "plateau.h"
#include "../game_log/plateau.h"
#include "../graphics/graphicalengine.h"
#include "../core/logger.h"

PlateauGraph::PlateauGraph(Plateau *p): m_plateau(p)
{
	m_engine = GraphicalEngine::GetInstance();
	m_item_plateau = new SceneNodeSpriteItem;
	m_nodePlateau = m_engine->GetSceneManager()->GetRootNode()->AddSceneNode();
	m_nodePlateau->AddItem(m_item_plateau);
	m_item_plateau->SetImage("data/plateau.jpg");
	sf::Vector2f sizePlateau = m_item_plateau->GetSize();
	m_item_plateau->SetRelativePosition(sf::Vector2f(-sizePlateau.x*0.5, -sizePlateau.y*0.5));
	m_camera = m_engine->GetCameraManager()->AddCamera();
	float ratio = m_engine->GetRenderWindow()->getSize().y/sizePlateau.y; 
	m_nodePlateau->SetAbsoluteScale(sf::Vector2f(ratio, ratio));

	sf::IntRect rTest = maisonRect(37);
	SceneNodeShapeItem *rect = new SceneNodeShapeItem;
	m_nodePlateau->AddItem(rect);
	rect->SetSize(sf::Vector2f(rTest.width, rTest.height));
	rect->SetRelativePosition(sf::Vector2f(rTest.left, rTest.top));
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
sf::IntRect PlateauGraph::maisonRect(int id) const
{
	if((id>=1&&id<=10)||(id>=21&&id<=29))
	{
		int idRel = id;
		if(idRel>10) 
		{
			idRel = id-21;
		}
		int debY = m_plateau->getTailleCase();
		int espace = m_item_plateau->GetSize().y-2*debY;
		espace     = espace /9;
		debY      += (idRel - 1) * espace;
		sf::IntRect rect;
		rect.left   = m_plateau->getEspaceMaison();
		rect.width  = m_plateau->getTailleCase() - m_plateau->getEspaceMaison();
		rect.top    = debY + espace;
		rect.height = espace;
		if(id<=10)
		{
			rect.top  = -rect.top + m_item_plateau->GetSize().y*0.5;
			rect.left = -m_item_plateau->GetSize().x*0.5 + rect.left;
		}
		else 
		{
			rect.top  = rect.top - m_item_plateau->GetSize().y*0.5;
			rect.left = m_item_plateau->GetSize().x*0.5 - rect.left - rect.width;
		}
		return rect;
	}
	else if((id>=11&&id<=19)||(id>=31&&id<=39)) 
	{
		int idRel = id;
		if(idRel>30) 
		{
			idRel = id-30+11;
		}
		int debX = m_plateau->getTailleCase();
		int espace = m_item_plateau->GetSize().x-2*debX;
		espace     = espace /9;
		debX      += (idRel - 11) * espace;
		sf::IntRect rect;
		rect.top   = m_plateau->getEspaceMaison();
		rect.height = m_plateau->getTailleCase() - m_plateau->getEspaceMaison();
		rect.left   = debX + espace;
		rect.width  = espace;
		if(id<=19)
		{
			rect.left = rect.left - m_item_plateau->GetSize().x*0.5 - rect.width;
			rect.top  = -m_item_plateau->GetSize().y*0.5 + rect.top;
		}
		else 
		{
			rect.left = -rect.left + m_item_plateau->GetSize().x*0.5 + rect.width; 
			rect.top  = m_item_plateau->GetSize().y*0.5 - rect.top - rect.height;
		}
		return rect;
	}
	return sf::IntRect();
}
