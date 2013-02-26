#ifndef MESSAGEBOX_H_INCLUDED
#define MESSAGEBOX_H_INCLUDED

#include <string>

class GuiWindowNode;
class GraphicalEngine;
class GuiItem;
class Plateau;
class Payer_ou_tirer;
class MessageBox
{
public:
    MessageBox(const std::string&, const std::string&, Plateau *plateau=nullptr, Payer_ou_tirer *carte=nullptr);
    bool wantPayed() const;
    static void payer(GuiItem*);
    static void tirer(GuiItem*);
private:
    Plateau *m_plateau;
    Payer_ou_tirer *m_carte;
    GuiWindowNode *m_window;
    GraphicalEngine *m_engine;
};

#endif // MESSAGEBOX_H_INCLUDED
