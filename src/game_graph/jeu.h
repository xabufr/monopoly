#ifndef H_JEU_H
#define H_JEU_H

class GraphicalEngine;
class GuiNode;
class GuiItem;
class GuiTextInputItem;
class JoueurGraph;
class PlateauGraph;
class Interface;
class Plateau;
class Jeu
{
public:
	Jeu();
	~Jeu();
	void run();
	static void menu_jouer(GuiItem*);
	static void quitter(GuiItem*);
	static void update_nb_joueurs(GuiItem*);
	static void continuer_jouer(GuiItem*);
	static void start_play(GuiItem*);
	enum state{
		main_menu,
		play_menu,
		continue_play_menu,
		play,
	};
	void changeState(state);
private:
	bool m_requ_change_state;
	state m_requ_state;
	GraphicalEngine *m_engine;
	void changeState();
	void setupMainMenu();
	void setupPlayMenu();
	void setupContinuePlayMenu();
	void setupPlay();
	GuiNode *m_sceneNode;
	int m_nb_joueurs;
	GuiTextInputItem* m_nomsJoueurs[8];
	Plateau *m_plateau;
	PlateauGraph *m_plateauGraph;
	JoueurGraph *m_joueurGraph[8];
	Interface *m_interface;
};

#endif