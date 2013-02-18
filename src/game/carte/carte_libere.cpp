#include "carte_libere.h"
#include "../joueur.h"

Carte_Libere::Carte_Libere(const std::string& descr, PaquetCarte* paquet)
: Carte(descr, paquet)
{

}


void Carte_Libere::tirer(Joueur* j)
{
    j->addCarteLiberte(this);
}

bool Carte_Libere::peutSeConserver() const
{
    return true;
}

bool Carte_Libere::estEnPossession() const
{
    return true;
}
