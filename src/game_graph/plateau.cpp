#include "plateau.h"
#include "../game_log/plateau.h"
#include "terrain.h"
#include "../game_log/case/casepropriete/caseterrain.h"
#include "../graphics/graphicalengine.h"
#include "../core/logger.h"
#include "../game_log/joueur.h"
#include "../game_log/case/case.h"

#include <iostream>

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
		CaseTerrain *t = dynamic_cast<CaseTerrain*>(c);
		if(t)
		{
			TerrainGraph *tG = new TerrainGraph(this, t, m_nodePlateau);
			m_terrains.push_back(tG);
		}
	}
	m_nodePlateau->SetAbsoluteScale(sf::Vector2f(ratio, ratio));
}
void PlateauGraph::update()
{

    DeplacerPion(1);
    sleep(0.3);
	for(TerrainGraph *terrain : m_terrains)
	{
		terrain->update();

	}
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

void PlateauGraph::DeplacerPion(int n)
{

    /**
        meme chose qu'afficher plateau
        creer noeud avec noeud parent = noeud plateau
        creer items pour pions

    */
	m_item_pion = new SceneNodeSpriteItem;
	m_nodepion = m_engine->GetSceneManager()->GetRootNode()->AddSceneNode();
	m_nodepion->AddItem(m_item_pion);
	m_item_pion->SetImage("data/pion.jpg");
	sf::Vector2f sizePion = m_item_pion->GetSize();
	m_item_pion->SetRelativePosition(sf::Vector2f(-270,250));


    m_plateau->avancerCurrentJoueur(n);
    int CooX =-270;
    int CooY =275;
    Joueur *j = m_plateau->getJoueurTour();
	int curPos = j->estSur()->id();

    int CaseCible = curPos+n;
    if (CaseCible > 40)
    {
        CaseCible -= 40;
    }

    if (CaseCible <= 10 )
    {
        CooY -= (47 * CaseCible);
    }
    else if (CaseCible == 11)
    {
        CooY -= 47 * CaseCible;
        CooX -= 24;
    }
    else if (CaseCible <= 20)
    {
        CooY -= 47 * 11 ;
        CooX = -290;
        CooX -= 47 * (10 - CaseCible);
    }
    else if (CaseCible == 21)
    {
        CooY -= 47 * 11;
        CooX = -290;
        CooX -= 50 * (10 - CaseCible);
    }
    else if (CaseCible <= 30)
    {
        CooX = 250;
        CooY = -250;
        CooY -= 47 * (21 - CaseCible);
    }
    else if (CaseCible == 31)
    {
        CooX = 250;
        CooY = 250;
    }
    else if (CaseCible <= 40)
    {
        CooX = 225;
        CooY = 250;
        CooX += 47 * (31 - CaseCible);
    }

	m_item_pion->SetRelativePosition(sf::Vector2f(CooX,CooY));

    /**
        nombre de cases * taille
        si case en coin, on add X ou Y en fonction de la case
    */


}

