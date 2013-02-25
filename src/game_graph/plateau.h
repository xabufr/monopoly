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
	~PlateauGraph();
	void update();
	sf::IntRect caseRect(int id) const;
	sf::IntRect maisonRect(int id) const;

private:
	SceneNodeSpriteItem *m_item_plateau;
	Plateau *m_plateau;
	SceneNode *m_nodePlateau;
	GraphicalEngine *m_engine;
	sf::View *m_camera;
	std::list<TerrainGraph*> m_terrains;
};

#endif
