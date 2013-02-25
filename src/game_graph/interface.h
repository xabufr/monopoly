#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

class Plateau;
class Jeu;
class GuiNode;
class GuiButtonItem;
class GuiItem;
class GraphicalEngine;
class Interface
{
public:
    Interface(Jeu*);
    ~Interface();
    static void lancerDes(GuiItem*);
    static void achat();
    static void hypothequer();
    static void tourSuivant();
    static void quitter(GuiItem*);
private:
    Plateau *m_plateau;
    Jeu *m_jeu;
    GuiNode *m_sceneNode;
	GuiButtonItem *m_button_des;
	GuiButtonItem *m_button_quitter;
	GraphicalEngine *m_engine;

};
#endif // INTERFACE_H_INCLUDED
