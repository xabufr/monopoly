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
class GuiWindowNode;
class MessageBox;
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
    static void construire(GuiItem*);
    static void construction(GuiItem*);
    static void detruire(GuiItem*);
    static void destruction(GuiItem*);
    static void liberer(GuiItem*);
    static void caution(GuiItem*);
    static void quitter(GuiItem*);
    static void closeHypotheque(GuiItem*);
    static void closeDeshypotheque(GuiItem*);
    static void closeConstruire(GuiItem*);
    static void closeDetruire(GuiItem*);
private:
    void m_show_window_hypothequer();
    void m_show_window_deshypothequer();
    void m_show_window_construire();
    void m_show_window_detruire();
    bool m_hypothequer;
    bool m_deshypothequer;
    bool m_construire;
    bool m_detruire;
    PlateauGraph *m_plateau;
    Jeu *m_jeu;
    MessageBox *m_message;
    GuiNode *m_sceneNode;
	GuiTextItem* m_info, *m_infoCase;
	GuiButtonItem *m_button_des;
	GuiButtonItem *m_button_quitter;
	GuiButtonItem *m_button_hypothequer;
	GuiButtonItem *m_button_deshypothequer;
	GuiButtonItem *m_button_construire;
	GuiButtonItem *m_button_detruire;
	GuiButtonItem *m_button_achat;
	GuiButtonItem *m_button_liberer;
	GuiButtonItem *m_button_caution;
	GuiWindowNode *m_window_hypothequer;
	GuiWindowNode *m_window_deshypothequer;
	GuiWindowNode *m_window_construire;
	GuiWindowNode *m_window_detruire;
	GraphicalEngine *m_engine;
    SceneNode *m_des[12];
	std::string m_lastInfos;
};
#endif // INTERFACE_H_INCLUDED
