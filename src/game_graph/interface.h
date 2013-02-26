#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <string>
class PlateauGraph;
class Jeu;
class GuiNode;
class GuiButtonItem;
class GuiItem;
class GraphicalEngine;
class SceneNode;
class GuiTextItem;
class Interface
{
public:
    Interface(Jeu*, PlateauGraph*);
    ~Interface();
    void update();
    static void lancerDes(GuiItem*);
    static void achat(GuiItem*);
    static void hypothequer_propriete(GuiItem*);
    static void deshypothequer_propriete(GuiItem*);
    static void hypothequer(GuiItem*);
    static void deshypothequer(GuiItem*);
    static void quitter(GuiItem*);
private:
    bool m_lancer;
    PlateauGraph *m_plateau;
    Jeu *m_jeu;
    GuiNode *m_sceneNode;
	GuiTextItem* m_info;
	GuiButtonItem *m_button_des;
	GuiButtonItem *m_button_quitter;
	GuiButtonItem *m_button_hypothequer;
	GuiButtonItem *m_button_deshypothequer;
	GuiButtonItem *m_button_achat;
	GraphicalEngine *m_engine;
    SceneNode *m_des[12];
	std::string m_lastInfos;
};
#endif // INTERFACE_H_INCLUDED
