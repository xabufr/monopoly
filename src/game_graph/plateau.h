#ifndef H_PLATEAU_GRAPH_H
#define H_PLATEAU_GRAPH_H
#include <SFML/Graphics.hpp>

class Plateau;
class SceneNodeSpriteItem;
class GraphicalEngine;
class SceneNode;
class PlateauGraph
{
public:
	PlateauGraph(Plateau*);
	void update();
	sf::IntRect caseRect(int id) const;
	sf::IntRect maisonRect(int id) const;
	void DeplacerPion(size_t);
private:
	SceneNodeSpriteItem *m_item_plateau;
	Plateau *m_plateau;
	SceneNode *m_nodePlateau;
	GraphicalEngine *m_engine;
	sf::View *m_camera;
};

#endif
