#ifndef H_PLATEAU_GRAPH_H
#define H_PLATEAU_GRAPH_H

#include <SFML/Graphics.hpp>

class Plateau;
class SceneNodeSpriteItem;
class GraphicalEngine;
class PlateauGraph
{
public:
	PlateauGraph(Plateau*);
	void update();
	sf::IntRect caseRect(int id) const;
private:
	SceneNodeSpriteItem *m_item_plateau;
	Plateau *m_plateau;
	GraphicalEngine *m_engine;
	sf::View *m_camera;
};

#endif 	
