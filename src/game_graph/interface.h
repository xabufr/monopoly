#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

class Plateau;
class Jeu;
class Interface
{
public:
    Interface(Jeu*);
    static void lancerDes();
    static void achat();
    static void hypothequer();
    static void tourSuivant();
    static void quitter();
private:
    Plateau *plateau;
    Jeu *m_jeu;
    GuiNode *m_sceneNode;
	GuiButtonItem *m_button_des;
	GuiButtonItem *m_button_quitter;
	Joueur *m_joueur;
	GraphicalEngine *m_engine;
};
#endif // INTERFACE_H_INCLUDED
