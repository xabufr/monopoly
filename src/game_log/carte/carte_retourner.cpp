#include "carte_retourner.h"
#include "../joueur.h"
#include "../plateau.h"
#include "paquet.h"

Carte_retourner::Carte_retourner(int id,const std::string& descr, PaquetCarte* paquet)
: Carte_aller_a(id, descr, paquet)
{
}
void Carte_retourner::tirer(Joueur* j)
{
    Plateau* temp_plateau = m_paquet->plateau();
    temp_plateau->placerCurrentJoueur(m_id,false);
}
