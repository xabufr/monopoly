#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_GRAPH_TERRAIN_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_GRAPH_TERRAIN_H__

#include "propriete.h"

class CaseTerrain;
class PlateauGraph;
class SceneNode;
class SceneNodeSpriteItem;
class TerrainGraph: public ProprieteGraph
{
public:
	TerrainGraph(PlateauGraph*, CaseTerrain*, SceneNode*);
	virtual ~TerrainGraph();
	virtual void update();
private:
	SceneNodeSpriteItem* m_maisons[5];
	SceneNode *m_nodeTerrain;
	CaseTerrain *m_terrain;
};

#endif
