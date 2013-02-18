#include "carte_aller_a.h"


Carte_aller_a::Carte_aller_a(int id,const std::string& descr, PaquetCarte* paquet)
: Carte(descr, paquet)
, m_id(id)
{

}
