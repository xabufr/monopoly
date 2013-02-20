#include "carte_aller_a.h"
#include "../joueur.h"
#include "../plateau.h"
#include "paquet.h"


Carte_aller_a::Carte_aller_a(int id,const std::string& descr, PaquetCarte* paquet)
: Carte(descr, paquet)
, m_id(id)
{

}



void Carte_aller_a::tirer(Joueur* j)
{
    Plateau* temp_plateau = m_paquet->plateau();
    temp_plateau->placerCurrentJoueur(m_id,true);
}

