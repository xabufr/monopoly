#ifndef MESSAGEBOX_H_INCLUDED
#define MESSAGEBOX_H_INCLUDED

class GuiWindowNode;
class GraphicalEngine;
namespace sf{
    class String;
}
class MessageBox
{
public:
    MessageBox(sf::String, sf::String);
private:
    GuiWindowNode *m_window;
    GraphicalEngine *m_engine;
};

#endif // MESSAGEBOX_H_INCLUDED
