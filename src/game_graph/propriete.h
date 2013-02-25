#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_GRAPH_PROPRIETE_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_GRAPH_PROPRIETE_H__

class PlateauGraph;
class CasePropriete;
class SceneNode;
class SceneNodeShapeItem;
class ProprieteGraph
{
public:
	ProprieteGraph(PlateauGraph*, CasePropriete*, SceneNode*);
	virtual ~ProprieteGraph();
	virtual void update();
protected:
	CasePropriete *m_case;
	PlateauGraph *m_plateau;
	SceneNode *m_node;
	SceneNodeShapeItem *m_item;
};

#endif 
