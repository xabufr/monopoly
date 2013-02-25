#include "casecarte.h"
#include "../joueur.h"
#include "../carte/carte.h"
#include "../carte/paquet.h"
#include "../carte/payer_ou_tirer.h"

CaseCarte::CaseCarte(size_t id, PaquetCarte *paq):Case(id, paq->nom()),  m_paquet(paq)
{

}
void CaseCarte::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    Carte *carte = m_paquet->tirer();
	j->setLastCarte(carte);
    if (dynamic_cast<Payer_ou_tirer*>(carte) != 0)
		;
	else
		carte->tirer(j);
}

