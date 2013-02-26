#include "carte_argent.h"
#include "../joueur.h"

Carte_argent::Carte_argent(int val,const std::string& descr, PaquetCarte* paquet)
: Carte(descr, paquet)
, m_valeur (val)
{

}
void Carte_argent::tirer(Joueur* j)
{

    if(m_valeur > 0)
    {
        j->crediter(m_valeur);
    }
    else
    {
        j->payer(-m_valeur);
    }

}
