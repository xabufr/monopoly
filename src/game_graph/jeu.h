#ifndef H_JEU_H
#define H_JEU_H

class GraphicalEngine;
class GuiNode;
class GuiItem;
class Jeu
{
public:
	Jeu();
	void run();
	static void menu_jouer(GuiItem*);
	static void quitter(GuiItem*);
	static void update_nb_joueurs(GuiItem*);
	static void continuer_jouer(GuiItem*);
	static void start_play(GuiItem*);
private:
	bool m_requ_change_state;
	enum state{
		main_menu,
		play_menu,
		continue_play_menu,
		play,
	}m_requ_state;
	GraphicalEngine *m_engine; 
	void changeState();
	void changeState(state);
	void setupMainMenu();
	void setupPlayMenu();
	void setupContinuePlayMenu();
	void setupPlay();
	GuiNode *m_sceneNode;
	int m_nb_joueurs;
};

#endif 
