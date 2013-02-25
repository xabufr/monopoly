#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_GRAPH_TERRAIN_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_GRAPH_TERRAIN_H__

class CaseTerrain;
class PlateauGraph;
class SceneNode;
class SceneNodeSpriteItem;
class TerrainGraph
{
public:
	TerrainGraph(PlateauGraph*, CaseTerrain*, SceneNode*);
	~TerrainGraph();
	void update();
private:
	SceneNodeSpriteItem* m_maisons[5];
	SceneNode *m_nodeTerrain;
	CaseTerrain *m_terrain;
	PlateauGraph *m_plateau;
};

#endif
