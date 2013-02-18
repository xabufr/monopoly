#include "carte_argent.h"

Carte_argent::Carte_argent(int val,const std::string& descr, PaquetCarte* paquet)
: Carte(descr, paquet)
, m_valeur (val)
{

}

