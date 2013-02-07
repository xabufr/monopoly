#include "conversion.h"
#include <sstream>

std::string int2string(int nb)
{
    std::ostringstream oss;
    oss << nb;
    return oss.str();
}
std::string key2string(sf::Keyboard::Key key)
{
    std::string name="";
    if(key>=sf::Keyboard::Key::A && key <=sf::Keyboard::Key::Z)
    {
        name="0";
        name[0] = 'A'-sf::Keyboard::Key::A + key;
    }
    else if(key>=sf::Keyboard::Key::Num0&&key<=sf::Keyboard::Key::Num9)
    {
        name="0";
        name[0] = '0'-sf::Keyboard::Key::Num0 + key;
    }
    else if(key>=sf::Keyboard::Key::Numpad0&&key<=sf::Keyboard::Key::Numpad9)
    {
        name="Numpad";
        name+='0'-sf::Keyboard::Key::Numpad0 + key;
    }
    else if(key>=sf::Keyboard::Key::F1&&key<=sf::Keyboard::Key::F9)
    {
        name="F";
        name+='1'-sf::Keyboard::Key::F1 + key;
    }
    else if(key>=sf::Keyboard::Key::F10&&key<=sf::Keyboard::Key::F15)
    {
        name="F1";
        name+='0'-sf::Keyboard::Key::F10 + key;
    }
    else if(key==sf::Keyboard::Key::Left)
        name="Fleche gauche";
    else if(key==sf::Keyboard::Key::Right)
        name="Fleche droite";
    else if(key==sf::Keyboard::Key::Up)
        name="Fleche haut";
    else if(key==sf::Keyboard::Key::Down)
        name="Fleche bas";
    else if(key==sf::Keyboard::Key::LControl)
        name="Ctrl gauche";
    else if(key==sf::Keyboard::Key::RControl)
        name="Ctrl droit";
    else if(key==sf::Keyboard::Key::LAlt)
        name="Alt gauche";
    else if(key==sf::Keyboard::Key::RAlt)
        name="Alt droit";
    else if(key==sf::Keyboard::Key::Space)
        name="Espace";
    else if(key==sf::Keyboard::Key::LShift)
        name="MAJ gauche";
    else if(key==sf::Keyboard::Key::RShift)
        name="MAJ droit";
    else if(key==sf::Keyboard::Key::Tab)
        name="Tab.";
    else if(key==sf::Keyboard::Key::Add)
        name="+";
    else if(key==sf::Keyboard::Key::Subtract)
        name="-";
    else
        name="Aucune touche";
    return name;
}
