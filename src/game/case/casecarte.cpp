#include "casecarte.h"
#include "../joueur.h"
#include "../carte/carte.h"
#include "../carte/paquet.h"

CaseCarte::CaseCarte(size_t id, const std::string& nom, PaquetCarte* paquet):Case(id, nom), m_paquet(paquet)
{

}

void CaseCarte::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    Carte *carte = m_paquet->tirer();
	carte->tirer(j);
}
