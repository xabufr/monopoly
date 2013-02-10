#include "joueur.h"

const std::string& Joueur::nom() const
{
	return m_nom;
}
int Joueur::argent() const
{
	return m_argent;
}
bool Joueur::estFauche() const
{
	return m_argent<=0;
}
void Joueur::payer(int val)
{
	m_argent-=val;
}
void Joueur::crediter(int val)
{
	m_argent+=val;
}
int Joueur::dernierLancer() const
{
	return m_dernier_lancer;
}
void Joueur::setDernierLancer(int der)
{
	m_dernier_lancer = der;
}
void Joueur::setPrison(bool prison)
{
	if(!m_prisonier&&prison)
		m_tours_prison=0;
	m_prisonier = prison;
}
bool Joueur::estEnPrison() const
{
	return m_prisonier;
}
void Joueur::ajouterTourPrison()
{
	++m_tours_prison;
}
int Joueur::getToursPrison() const
{
	return m_tours_prison;
}
Case* Joueur::estSur() const
{
	return m_CasePosition;
}
void Joueur::positinner(Case* pos)
{
	m_CasePosition=pos;
}
