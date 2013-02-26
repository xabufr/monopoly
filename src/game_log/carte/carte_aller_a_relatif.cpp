#include "carte_aller_a_relatif.h"
#include "../joueur.h"
#include "../plateau.h"
#include "paquet.h"
#include <iostream>

Carte_aller_a_relatif::Carte_aller_a_relatif(int id,const std::string& descr, PaquetCarte* paquet)
: Carte_aller_a(id,descr, paquet)
{

}
void Carte_aller_a_relatif::tirer(Joueur* j)
{
    Plateau* temp_plateau = m_paquet->plateau();
    temp_plateau->avancerCurrentJoueur(m_id);
	std::cout << "-----+" << m_id << " relatif"<<std::endl;
}
