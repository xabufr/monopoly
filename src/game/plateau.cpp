#include "plateau.h"
#include "joueur.h"
#include "case/case.h"
#include "case/caseprison.h"
#include <rapidxml.hpp>

Plateau::Plateau()
{

}
void Plateau::addArgent(int a)
{
	m_argent += a;
}
void Plateau::viderArgent()
{
	m_argent = 0;
}
int Plateau::getArgent() const
{
	return m_argent;
}
void Plateau::emprisoner(Joueur* j)
{
	j->setPrison(true);
}
void Plateau::liberer(Joueur* j)
{
	j->setPrison(true);
}
Joueur* Plateau::getJoueurTour() const
{
	return m_joueurs[m_index_current_joueur];
}
void Plateau::joueurTourFinit()
{
	if(++m_index_current_joueur == m_joueurs.size())
		m_index_current_joueur = 0;
	Joueur *j = getJoueurTour();
	if(j->estEnPrison())
		j->ajouterTourPrison();
}
Plateau::EtatPlateau Plateau::etatPlateau() const
{
	return m_etat;
}
void Plateau::setEtatPlateau(EtatPlateau e)
{
	m_etat = e;
}
void Plateau::avancerCurrentJoueur(int dep)
{
	Joueur *j = getJoueurTour();
	size_t curPos = j->estSur()->id();
	m_case[curPos]->joueurPart(j);
	for(int i=0;i<dep-1;++i)
	{
		if(++curPos==40)
			curPos=0;
		m_case[curPos]->joueurPasse(j);
	}
	if(++curPos==40)
		curPos=0;
	m_case[curPos]->joueurArrive(j);
	j->positinner(m_case[curPos]);
}
void Plateau::placerCurrentJoueur(int id, bool passerDepart)
{
	Joueur *j = getJoueurTour();
	if(passerDepart)
	{
		int dep   = id - j->estSur()->id();
		if(dep<0)
			dep = 40 + dep;
		avancerCurrentJoueur(dep);
	}
	else
	{
		j->estSur()->joueurPart(j);
		m_case[id]->joueurArrive(j);
		j->positinner(m_case[id]);
	}
}

std::vector<Joueur*> Plateau::GetJoueurs()
{
    return m_joueurs;
}
