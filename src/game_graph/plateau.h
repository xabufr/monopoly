#ifndef H_PLATEAU_GRAPH_H
#define H_PLATEAU_GRAPH_H

class Plateau;
class SceneNodeSpriteItem;
class GraphicalEngine;
class PlateauGraph
{
public:
	PlateauGraph(Plateau*);
private:
	SceneNodeSpriteItem *m_item_plateau;
	Plateau *m_plateau;
	GraphicalEngine *m_engine;
};

#endif 	
