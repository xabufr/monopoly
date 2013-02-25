#include "paquet.h"
#include "../../core/random.h"
#include <iterator>
#include "carte.h"
#include <iostream>

PaquetCarte::PaquetCarte(int type, const std::string& nom, const std::string& logo, Plateau* plateau): m_type(type), m_nom(nom), m_chemin_logo(logo), m_plateau(plateau)
{
}
PaquetCarte::~PaquetCarte()
{
	for(Carte* c : m_cartes)
		delete c;
}
int PaquetCarte::type() const
{
	return m_type;
}
const std::string& PaquetCarte::nom() const
{
	return m_nom;
}
const std::list<Carte*>& PaquetCarte::cartes() const
{
	return m_cartes;
}
const std::string& PaquetCarte::cheminLogo() const
{
	return m_chemin_logo;
}
Carte* PaquetCarte::tirer()
{
	Carte* carte;
	do
	{
		carte = m_cartes.front();
		m_cartes.pop_front();
		m_cartes.push_back(carte);
		std::cout << carte->description() << std::endl;
	}while(carte->estEnPossession());
	return carte;
}
Plateau* PaquetCarte::plateau() const
{
	return m_plateau;
}
void PaquetCarte::ajouterCarte(Carte* c)
{
	m_cartes.push_back(c);
}
void PaquetCarte::melanger()
{
	std::list<Carte*> paquetTemp;
	while(!m_cartes.empty())
	{
		std::list<Carte*>::iterator it = m_cartes.begin();
		size_t index = Random::Rand(0, m_cartes.size()-1);
		std::advance(it, index);
		paquetTemp.push_back(*it);
		m_cartes.erase(it);
	}
	m_cartes = paquetTemp;
}
