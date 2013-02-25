#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <SFML/Graphics/Color.hpp>

class SceneNodeSpriteItem;
class GraphicalEngine;
class GuiNode;
class GuiTextItem;
class GuiContener;
class Joueur;
class SceneNodeCircleShapeItem;
class GraphicalEngine;
class PlateauGraph;
class SceneNode;
namespace sf {
	class View;
} // namespace sf
class JoueurGraph
{
public:
	JoueurGraph(Joueur*,SceneNode *nodeparent,PlateauGraph *plateau);
	~JoueurGraph();
	void stat(float) const;
	void update();
	const sf::Color& couleur() const;
	void setCouleur(const sf::Color&);
	Joueur* joueur() const;
private:
	GuiNode *m_sceneNode;
	Joueur *m_joueur;
	SceneNodeCircleShapeItem *m_item_pion;
	SceneNode *m_nodepion;
	GuiTextItem *m_item_stat_joueur;
	GraphicalEngine *m_engine;
	PlateauGraph *m_plateau;
	sf::Color m_couleur;
};

#endif // JOUEUR_H_INCLUDED
