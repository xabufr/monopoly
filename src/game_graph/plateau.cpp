#include "plateau.h"
#include "../game_log/plateau.h"
#include "terrain.h"
#include "../game_log/case/casepropriete/caseterrain.h"
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

	for (size_t i = 0; i < 40; ++i)
	{
		Case *c        = m_plateau->getCase(i);
		CasePropriete *p = dynamic_cast<CasePropriete*>(c);
		if(p)
		{
			CaseTerrain *t = dynamic_cast<CaseTerrain*>(p);
			if(t)
			{
				TerrainGraph *tG = new TerrainGraph(this, t, m_nodePlateau);
				m_terrains.push_back(tG);
			}
			else
			{
				ProprieteGraph *pG = new ProprieteGraph(this, p, m_nodePlateau);
				m_terrains.push_back(pG);
			}
		}
	}
	m_nodePlateau->SetAbsoluteScale(sf::Vector2f(ratio, ratio));
}
PlateauGraph::~PlateauGraph()
{
	m_engine->GetSceneManager()->RemoveNode(m_nodePlateau);
	delete m_plateau;
}
void PlateauGraph::update()
{
	for(ProprieteGraph *terrain : m_terrains)
	{
		terrain->update();
	}
}
sf::IntRect PlateauGraph::caseRect(int id) const
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
		rect.left   = m_plateau->getEspaceMaison() + m_plateau->getTailleTraits();
		rect.width  = m_plateau->getTailleCase();
		rect.top    = debY + espace;
		rect.height = espace - m_plateau->getTailleTraits();// - m_plateau->getTailleTraits();
		if(id<=10)
		{
			rect.top  = -rect.top + m_item_plateau->GetSize().y*0.5;
			rect.left = -m_item_plateau->GetSize().x*0.5;
		}
		else
		{
			rect.top  = rect.top - m_item_plateau->GetSize().y*0.5 + m_plateau->getTailleTraits();
			rect.left = m_item_plateau->GetSize().x*0.5 - rect.width;
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
		rect.top   = m_plateau->getEspaceMaison() + m_plateau->getTailleTraits();
		rect.height = m_plateau->getTailleCase(); 
		rect.left   = debX + espace;
		rect.width  = espace - m_plateau->getTailleTraits();
		if(id<=19)
		{
			rect.left = rect.left - m_item_plateau->GetSize().x*0.5 - rect.width;
			rect.top  = -m_item_plateau->GetSize().y*0.5 ;
		}
		else
		{
			rect.left = -rect.left + m_item_plateau->GetSize().x*0.5 + rect.width + m_plateau->getTailleTraits();
			rect.top  = m_item_plateau->GetSize().y*0.5 - rect.height;
		}
		return rect;
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
		rect.left   = m_plateau->getEspaceMaison() + m_plateau->getTailleTraits();
		rect.width  = m_plateau->getTailleCase() - m_plateau->getEspaceMaison() - m_plateau->getTailleTraits();
		rect.top    = debY + espace;
		rect.height = espace - m_plateau->getTailleTraits();// - m_plateau->getTailleTraits();
		if(id<=10)
		{
			rect.top  = -rect.top + m_item_plateau->GetSize().y*0.5;
			rect.left = -m_item_plateau->GetSize().x*0.5 + rect.left;
		}
		else
		{
			rect.top  = rect.top - m_item_plateau->GetSize().y*0.5 + m_plateau->getTailleTraits();
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
		rect.top   = m_plateau->getEspaceMaison() + m_plateau->getTailleTraits();
		rect.height = m_plateau->getTailleCase() - m_plateau->getEspaceMaison() - m_plateau->getTailleTraits();
		rect.left   = debX + espace;
		rect.width  = espace - m_plateau->getTailleTraits();
		if(id<=19)
		{
			rect.left = rect.left - m_item_plateau->GetSize().x*0.5 - rect.width;
			rect.top  = -m_item_plateau->GetSize().y*0.5 + rect.top;
		}
		else
		{
			rect.left = -rect.left + m_item_plateau->GetSize().x*0.5 + rect.width + m_plateau->getTailleTraits();
			rect.top  = m_item_plateau->GetSize().y*0.5 - rect.top - rect.height;
		}
		return rect;
	}
	return sf::IntRect();
}
JoueurGraph* PlateauGraph::findJoueurGraph(Joueur* j) const
{
	auto it = m_joueurs.find(j);
	if(it != m_joueurs.end())
		return it->second;
	return nullptr;
}
