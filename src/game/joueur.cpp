#include "joueur.h"
#include "carte/carte_libere.h"
#include "case/casepropriete/casegare.h"
#include "case/casepropriete/casecompagnie.h"

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
int Joueur::getNombreGare() const
{
    int i=0;
    for(auto it=m_proprietes.begin(); it!=m_proprietes.end();++it)
	{
		if(dynamic_cast<CaseGare*>(*it)!=0)
            ++i;
	}
	return i;
}

int Joueur::getNombreCompagnie() const
{
    int i=0;
    for(auto it=m_proprietes.begin(); it!=m_proprietes.end();++it)
	{
		if(dynamic_cast<CaseCompagnie*>(*it)!=0)
            ++i;
	}
	return i;
}

Case* Joueur::estSur() const
{
	return m_CasePosition;
}
void Joueur::positinner(Case* pos)
{
	m_CasePosition=pos;
}

void Joueur::addCarteLiberte(Carte_Libere* c)
{
    m_cartes_liberte.push_back(c);
}

void Joueur::addPropriete(CasePropriete* p)
{
    m_proprietes.push_back(p);
}
