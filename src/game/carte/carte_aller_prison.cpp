#include "carte_aller_prison.h"
#include "../plateau.h"
#include "paquet.h"

Carte_aller_en_prison::Carte_aller_en_prison(const std::string& descr, PaquetCarte* paquet)
: Carte(descr, paquet)
{

}

void Carte_aller_en_prison::tirer(Joueur* j)
{
    Plateau* temp_plateau = m_paquet->plateau();
    temp_plateau->emprisoner(j);
}
