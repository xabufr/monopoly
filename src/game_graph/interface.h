#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

class PlateauGraph;
class Jeu;
class GuiNode;
class GuiButtonItem;
class GuiItem;
class GraphicalEngine;
class SceneNode;
class Interface
{
public:
    Interface(Jeu*, PlateauGraph*);
    ~Interface();
    static void lancerDes(GuiItem*);
    static void achat();
    static void hypothequer();
    static void tourSuivant();
    static void quitter(GuiItem*);
private:
    PlateauGraph *m_plateau;
    Jeu *m_jeu;
    GuiNode *m_sceneNode;
	GuiButtonItem *m_button_des;
	GuiButtonItem *m_button_quitter;
	GraphicalEngine *m_engine;
    SceneNode *m_des[12];
};
#endif // INTERFACE_H_INCLUDED
