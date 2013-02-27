#include "carte_libere.h"
#include "../joueur.h"
#include "paquet.h"
#include "../plateau.h"

Carte_Libere::Carte_Libere(const std::string& descr, PaquetCarte* paquet)
: Carte(descr, paquet), m_proprietaire(nullptr)
{

}
void Carte_Libere::tirer(Joueur* j)
{
    j->addCarteLiberte(this);
	m_proprietaire=j;
}
bool Carte_Libere::peutSeConserver() const
{
    return true;
}
bool Carte_Libere::estEnPossession() const
{
    return m_proprietaire!=nullptr;
}
void Carte_Libere::utiliser()
{
	if(m_proprietaire)
	{
		this->m_paquet->plateau()->liberer(m_proprietaire);
		m_proprietaire->delCarteLiberte(this);
		m_proprietaire = nullptr;
	}
}
