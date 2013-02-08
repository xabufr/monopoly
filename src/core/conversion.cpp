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
    if(key>=sf::Keyboard::A && key <=sf::Keyboard::Z)
    {
        name="0";
        name[0] = 'A'-sf::Keyboard::A + key;
    }
    else if(key>=sf::Keyboard::Num0&&key<=sf::Keyboard::Num9)
    {
        name="0";
        name[0] = '0'-sf::Keyboard::Num0 + key;
    }
    else if(key>=sf::Keyboard::Numpad0&&key<=sf::Keyboard::Numpad9)
    {
        name="Numpad";
        name+='0'-sf::Keyboard::Numpad0 + key;
    }
    else if(key>=sf::Keyboard::F1&&key<=sf::Keyboard::F9)
    {
        name="F";
        name+='1'-sf::Keyboard::F1 + key;
    }
    else if(key>=sf::Keyboard::F10&&key<=sf::Keyboard::F15)
    {
        name="F1";
        name+='0'-sf::Keyboard::F10 + key;
    }
    else if(key==sf::Keyboard::Left)
        name="Fleche gauche";
    else if(key==sf::Keyboard::Right)
        name="Fleche droite";
    else if(key==sf::Keyboard::Up)
        name="Fleche haut";
    else if(key==sf::Keyboard::Down)
        name="Fleche bas";
    else if(key==sf::Keyboard::LControl)
        name="Ctrl gauche";
    else if(key==sf::Keyboard::RControl)
        name="Ctrl droit";
    else if(key==sf::Keyboard::LAlt)
        name="Alt gauche";
    else if(key==sf::Keyboard::RAlt)
        name="Alt droit";
    else if(key==sf::Keyboard::Space)
        name="Espace";
    else if(key==sf::Keyboard::LShift)
        name="MAJ gauche";
    else if(key==sf::Keyboard::RShift)
        name="MAJ droit";
    else if(key==sf::Keyboard::Tab)
        name="Tab.";
    else if(key==sf::Keyboard::Add)
        name="+";
    else if(key==sf::Keyboard::Subtract)
        name="-";
    else
        name="Aucune touche";
    return name;
}
