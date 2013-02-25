#include "plateau.h"
#include "../game_log/plateau.h"
#include "../graphics/graphicalengine.h"
#include "../core/logger.h"
#include "../game_log/joueur.h"
#include "../game_log/case/case.h"

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

	sf::IntRect rTest = maisonRect(34);
	SceneNodeShapeItem *rect = new SceneNodeShapeItem;
	m_nodePlateau->AddItem(rect);
	rect->SetSize(sf::Vector2f(rTest.width, rTest.height));
	rect->SetRelativePosition(sf::Vector2f(rTest.left, rTest.top));
}
void PlateauGraph::update()
{
   /* char str[1];
    int n;

    printf("lancer le dé?");
    n = rand() % 10 + 1;
*/
    size_t n = 1;
    DeplacerPion(n);
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

void PlateauGraph::DeplacerPion(size_t n)
{

    /**
        meme chose qu'afficher plateau
        creer noeud avec noeud parent = noeud plateau
        creer items pour pions

    */


    m_plateau->avancerCurrentJoueur(n);
    size_t CooX =0;
    size_t CooY =0;
    Joueur *j = m_plateau->getJoueurTour();
	size_t curPos = j->estSur()->id();

    size_t CaseCible = curPos+n;

    if (CaseCible <= 9)
    {
        CooX = (m_plateau->getTailleCase() * CaseCible * 2) + m_plateau->getTailleCase() * 2;
        // +1 pour la 1ere case qui en vaut le double
    }
    else if (CaseCible == 10)
    {
        //prison
    }
    else if (CaseCible <= 20)
    {
        CooX = m_plateau->getTailleCase() * 10 * 2;
        CooY = (m_plateau->getTailleCase() * CaseCible) + m_plateau->getTailleCase();
    }
    else if (CaseCible <= 30)
    {
        CooX = m_plateau->getTailleCase() * 10 * 2;
        CooY = m_plateau->getTailleCase() * 10;
        CooY -= (m_plateau->getTailleCase() * CaseCible) + m_plateau->getTailleCase();
    }
    else if (CaseCible <= 40)
    {
        CooY = 0;
        CooX = m_plateau->getTailleCase() * 10 *2;
        CooX -= (m_plateau->getTailleCase() * CaseCible * 2) + m_plateau->getTailleCase() *2;
    }

    /**
        nombre de cases * taille
        si case en coin, on add X ou Y en fonction de la case
    */


}

