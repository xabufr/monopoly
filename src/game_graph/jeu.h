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
private:
	bool m_requ_change_state;
	enum state{
		main_menu,
		play_menu,
	}m_requ_state;
	GraphicalEngine *m_engine; 
	void changeState();
	void changeState(state);
	void setupMainMenu();
	void setupPlayMenu();
	GuiNode *m_sceneNode;
};

#endif 
