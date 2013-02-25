#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

class SceneNodeSpriteItem;
class GraphicalEngine;
class GuiNode;
class GuiTextItem;
class GuiContener;
class Joueur;
namespace sf {
	class View;
} // namespace sf
class JoueurGraph
{
public:
	JoueurGraph(Joueur*);
	~JoueurGraph();
	void stat(float) const;
private:
	GuiNode *m_sceneNode;
	Joueur *m_joueur;
	GuiTextItem *m_item_stat_joueur;
	GraphicalEngine *m_engine;
};

#endif // JOUEUR_H_INCLUDED
