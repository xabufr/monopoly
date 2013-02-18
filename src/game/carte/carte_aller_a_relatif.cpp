#include "carte_aller_a_relatif.h"
#include "../joueur.h"
#include "../plateau.h"
#include "paquet.h"

Carte_aller_a_relatif::Carte_aller_a_relatif(int id,const std::string& descr, PaquetCarte* paquet, int deplacement)
: Carte_aller_a(id,descr, paquet)
, m_deplacement (deplacement)
{

}

void Carte_aller_a_relatif::tirer(Joueur* j)
{
    Plateau* temp_plateau = m_paquet->plateau();
    temp_plateau->avancerCurrentJoueur(m_deplacement);
}

