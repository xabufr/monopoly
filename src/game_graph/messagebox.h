#ifndef MESSAGEBOX_H_INCLUDED
#define MESSAGEBOX_H_INCLUDED

#include <string>

class GuiWindowNode;
class GraphicalEngine;
class MessageBox
{
public:
    MessageBox(const std::string&, const std::string&);
private:
    GuiWindowNode *m_window;
    GraphicalEngine *m_engine;
};

#endif // MESSAGEBOX_H_INCLUDED
