#ifndef H_PLATEAU_GRAPH_H
#define H_PLATEAU_GRAPH_H
#include <SFML/Graphics.hpp>
#include <list>

class Plateau;
class SceneNodeSpriteItem;
class GraphicalEngine;
class SceneNode;
class TerrainGraph;
class PlateauGraph
{
public:
	PlateauGraph(Plateau*);
	void update();
	sf::IntRect caseRect(int id) const;
	sf::IntRect maisonRect(int id) const;
	void DeplacerPion(int );

private:
	SceneNodeSpriteItem *m_item_plateau,*m_item_pion;
	Plateau *m_plateau;
	SceneNode *m_nodePlateau,*m_nodepion;
	GraphicalEngine *m_engine;
	sf::View *m_camera;
	std::list<TerrainGraph*> m_terrains;
};

#endif
