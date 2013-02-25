#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <SFML/Graphics/Color.hpp>

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
	const sf::Color& couleur() const;
	void setCouleur(const sf::Color&);
	Joueur* joueur() const;
private:
	GuiNode *m_sceneNode;
	Joueur *m_joueur;
	GuiTextItem *m_item_stat_joueur;
	GraphicalEngine *m_engine;
	sf::Color m_couleur;
};

#endif // JOUEUR_H_INCLUDED
