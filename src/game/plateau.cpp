#include "plateau.h"
#include "joueur.h"
#include "carte/paquet.h"
#include "case/case.h"
#include "case/casepropriete/casegare.h"
#include "case/caseprison.h"
#include "../../rapidxml/rapidxml.hpp"
#include <fstream>
#include <iostream>
#include <boost/lexical_cast.hpp>

Plateau::Plateau()
{
	std::ifstream file;
	file.open("config.xml");
	if(!file)
	{
		std::cout << "Fichier config.xml manquant" << std::endl;
		exit(0);
	}
	file.seekg(0, std::ios_base::end);
	const int length = file.tellg();
	char *buffer     = new char[length+1];
	file.seekg(0, std::ios_base::beg);
	file.read(buffer, length);
	buffer[length] = 0;
	rapidxml::xml_document<> document;
	document.parse<0>(buffer);

	rapidxml::xml_node<> *root = document.first_node("jeu");

	rapidxml::xml_node<> *plateau = root->first_node("plateau");
	/*
	 * Chargement des cases
	 */
	rapidxml::xml_node<> *node;
	for (node=plateau->first_node();node;node=node->next_sibling())
	{
		std::string type = node->name();
		if (type=="groupe")
		{
		}
		else
		{
			Case *currCase;
			size_t id = boost::lexical_cast<size_t>(node->first_attribute("id")->value());
			if(type=="taxe") 
			{
			}
			else if(type=="compagnie") 
			{
				
			}
			else if(type=="gare") 
			{
				
			}
			else if(type=="depart") 
			{
				
			}
			else if(type=="prison") 
			{
				
			}
			else if(type=="police") 
			{
				
			}
			else if(type=="parc") 
			{
				
			}
			else if(type=="carte") 
			{
				
			}
			m_case[id] = currCase;
		}
	}
	rapidxml::xml_node<> *cartes = root->first_node("cartes");
	rapidxml::xml_node<> *paquet;
	for(paquet=cartes->first_node("paquet");paquet;paquet=paquet->next_sibling("paquet")) 
	{
		int type        = boost::lexical_cast<int>(paquet->first_attribute("type")->value());
		std::string nom = paquet->first_attribute("nom")->value();
		m_paquets[type] = new PaquetCarte(type, nom, "", this);
		for(node=paquet->first_node("carte");node;node=node->next_sibling("carte")) 
		{
			Carte *carte=nullptr;
			m_paquets[type]->ajouterCarte(carte);
		}
	}
	delete buffer;
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
	j->estSur()->joueurPart(j);
	j->positinner(m_prison);
	m_prison->joueurArrive(j);
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

