#include "carte_reparation.h"

Carte_reparation::Carte_reparation(bool hotel,int maison,const std::string& descr, PaquetCarte* paquet)
: Carte(descr, paquet)
, m_hotel(hotel)
, m_maison(maison)
{

}
Carte_reparation::~Carte_reparation()
{
    delete this;
}
