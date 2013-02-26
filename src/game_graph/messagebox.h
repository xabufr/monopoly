#ifndef MESSAGEBOX_H_INCLUDED
#define MESSAGEBOX_H_INCLUDED

#include <string>

class GuiWindowNode;
class GraphicalEngine;
class MessageBox
{
public:
    MessageBox(const std::string&, const std::string&, bool);
    bool wantPayed() const;
    static void payer(GuiItem*);
    static void tirer(GuiItem*);
private:
    bool m_payer;
    GuiWindowNode *m_window;
    GraphicalEngine *m_engine;
};

#endif // MESSAGEBOX_H_INCLUDED
