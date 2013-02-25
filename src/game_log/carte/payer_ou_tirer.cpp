#include "payer_ou_tirer.h"
#include "paquet.h"
#include "../joueur.h"

Payer_ou_tirer::Payer_ou_tirer(int val,const std::string& descr, PaquetCarte* paquet_source, PaquetCarte* paquet_cible)
: Carte_argent( val, descr, paquet_source)
, m_paquet_cible (paquet_cible)
{

}
void Payer_ou_tirer::tirer(Joueur* j)
{
	if(m_valeur > 0)
	{
		j->crediter(m_valeur);
	}
	else
	{
		j->payer(m_valeur);
	}
}
PaquetCarte* Payer_ou_tirer::paquetAutre() const
{
	return m_paquet_cible;
}
void Payer_ou_tirer::setPaquetAutre(PaquetCarte *a)
{
	m_paquet_cible = a;
}