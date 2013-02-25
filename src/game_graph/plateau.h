#ifndef H_PLATEAU_GRAPH_H
#define H_PLATEAU_GRAPH_H

#include <SFML/Graphics.hpp>
#include <list>
#include <map>

class Plateau;
class SceneNodeSpriteItem;
class GraphicalEngine;
class SceneNode;
class ProprieteGraph;
class JoueurGraph;
class Joueur;
class PlateauGraph
{
public:
	PlateauGraph(Plateau*);
	~PlateauGraph();
	void update();
	sf::IntRect caseRect(int id) const;
	sf::IntRect maisonRect(int id) const;
	JoueurGraph* findJoueurGraph(Joueur*) const;

private:
	SceneNodeSpriteItem *m_item_plateau;
	Plateau *m_plateau;
	SceneNode *m_nodePlateau;
	GraphicalEngine *m_engine;
	sf::View *m_camera;
	std::list<ProprieteGraph*> m_terrains;
	std::map<Joueur*, JoueurGraph*> m_joueurs;
};

#endif
