#include "plateau.h"
#include "joueur.h"
//include cartes
#include "carte/paquet.h"
#include "carte/carte_argent.h"
#include "carte/carte_argent_depuis_joueur.h"
#include "carte/carte_reparation.h"
#include "carte/carte_aller_a.h"
#include "carte/carte_aller_a_relatif.h"
#include "carte/carte_aller_prison.h"
#include "carte/payer_ou_tirer.h"
#include "carte/carte_libere.h"
#include "carte/carte_retourner.h"
//Inclues cases
#include "case/case.h"
#include "case/casepropriete/casegare.h"
#include "case/casepropriete/casecompagnie.h"
#include "case/casepropriete/caseterrain.h"
#include "case/casepropriete/groupeterrain.h"
#include "case/caseprison.h"
#include "case/casetaxe.h"
#include "case/casedepart.h"
#include "case/caseallerenprison.h"
#include "case/caseparkinggratuit.h"
#include "case/casecarte.h"
//end include cases
#include "../../rapidxml/rapidxml.hpp"
#include <fstream>
#include <iostream>
#include <utility>
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
	rapidxml::xml_node<> *cartes = root->first_node("cartes");
	rapidxml::xml_node<> *node;
	rapidxml::xml_node<> *paquet;

	rapidxml::xml_node<>* nComp = root->first_node("compagnie");
	rapidxml::xml_node<> *nGare = root->first_node("gare");
	int multiplicateurs_compagnies[2];
	int loyers_gare[4];
	int credit_tour;
	int prix_gare, prix_compagnie;
	int hyp_gare, hyp_compagnie;

	prix_compagnie = boost::lexical_cast<int>(nComp->first_attribute("prix")->value());
	for (size_t i = 0; i < 2; ++i)
	{
		multiplicateurs_compagnies[i] = boost::lexical_cast<int>(
				nComp->first_attribute(("mul"+boost::lexical_cast<std::string>(i+1)).c_str())->value());
	}
	hyp_compagnie = boost::lexical_cast<int>(nComp->first_attribute("hyp")->value());

	prix_gare = boost::lexical_cast<int>(nGare->first_attribute("prix")->value());
	for (size_t i = 0; i < 4; ++i)
	{
		loyers_gare[i] = boost::lexical_cast<int>(nGare->first_attribute(("t"+boost::lexical_cast<std::string>(i)).c_str())->value());
	}
	hyp_gare    	= boost::lexical_cast<int>(nGare->first_attribute("hyp")->value());
	credit_tour 	= boost::lexical_cast<int>(root->first_node("joueur")->first_attribute("argent_tour")->value());
	m_argent_depart = boost::lexical_cast<int>(root->first_node("joueur")->first_attribute("argent_depart")->value());

	std::list<std::pair<Carte*, int>> cacheLiensCarte; // Pour les cartes "argent tirer"
	for(paquet=cartes->first_node("paquet");paquet;paquet=paquet->next_sibling("paquet")) 
	{
		int type        = boost::lexical_cast<int>(paquet->first_attribute("type")->value());
		std::string nom = paquet->first_attribute("nom")->value();
		PaquetCarte *curPaq = m_paquets[type] = new PaquetCarte(type, nom, "", this);
		for(node=paquet->first_node("carte");node;node=node->next_sibling("carte")) 
		{
			Carte *carte=nullptr;
			std::string type = node->first_attribute("type")->value();
			std::string description = node->first_attribute("lib")->value();
			if(type=="aller_prison")
			{
				carte = new Carte_aller_en_prison(description, curPaq);
			}
			else if(type=="retourner") 
			{
				carte = new Carte_retourner(boost::lexical_cast<int>(node->first_attribute("id")->value()), description, curPaq);
			}
			else if(type=="aller_a") 
			{
				carte = new Carte_aller_a(boost::lexical_cast<int>(node->first_attribute("id")->value()),
						description, curPaq);
			}
			else if(type=="libere") 
			{
				carte = new Carte_Libere(description, curPaq);
			}
			else if(type=="argent") 
			{
				carte = new Carte_argent(boost::lexical_cast<int>(node->first_attribute("valeur")->value()),
						description, curPaq);
			}
			else if(type=="reparation") 
			{
				carte = new Carte_reparation(boost::lexical_cast<int>(node->first_attribute("hotel")->value()),
						boost::lexical_cast<int>(node->first_attribute("maison")->value()),
						description, curPaq);
			}
			else if(type=="aller_relatif") 
			{
				carte = new Carte_aller_a_relatif(boost::lexical_cast<int>(node->first_attribute("dep")->value()),
						description, curPaq);
			}
			else if(type=="argent_tirer") 
			{
				carte = new Payer_ou_tirer(boost::lexical_cast<int>(node->first_attribute("valeur")->value()), description, curPaq, nullptr);
				cacheLiensCarte.push_back(std::pair<Carte*,int>(carte, boost::lexical_cast<int>(node->first_attribute("autre")->value())));
			}
			else if(type=="argent_depuis_joueurs") 
			{
				carte = new Carte_argent_depuis_joueur(boost::lexical_cast<int>(node->first_attribute("valeur")->value()),
						description, curPaq);
			}
			curPaq->ajouterCarte(carte);
		}
	}
	//Pseudo édition de liens
	for(auto it = cacheLiensCarte.begin();it!=cacheLiensCarte.end();++it) 
	{
		((Payer_ou_tirer*)it->first)->setPaquetAutre(m_paquets[it->second]);
	}
	for (node=plateau->first_node();node;node=node->next_sibling())
	{
		std::string type = node->name();
		if (type=="groupe")
		{
			sf::Color color;
			GroupeTerrain *groupe = new GroupeTerrain(color, node->first_attribute("couleur")->value(),
					boost::lexical_cast<int>(node->first_attribute("maison")->value()));
			rapidxml::xml_node<>* nodeTerrain;
			for(nodeTerrain=node->first_node("terrain");nodeTerrain;nodeTerrain=nodeTerrain->next_sibling("terrain")) 
			{
				int id = boost::lexical_cast<int>(nodeTerrain->first_attribute("id")->value());
				CaseTerrain *terrain = new CaseTerrain(id, nodeTerrain->first_attribute("nom")->value());
				terrain->setPrix(boost::lexical_cast<int>(nodeTerrain->first_attribute("prix")->value()));
				terrain->setHypotheque(boost::lexical_cast<int>(nodeTerrain->first_attribute("hyp")->value()));
				terrain->setGroupe(groupe);
				for (size_t i = 0; i < 6; ++i)
				{
					terrain->setLoyer(i, 
							boost::lexical_cast<int>(
								nodeTerrain->first_attribute(("t"+boost::lexical_cast<std::string>(i)).c_str())->value())
							);
				}
			}
		}
		else
		{
			Case *currCase;
			size_t id = boost::lexical_cast<size_t>(node->first_attribute("id")->value());
			if(type=="taxe") 
			{
				currCase = new CaseTaxe(id, 
						boost::lexical_cast<int>(node->first_attribute("prix")->value()),
						node->first_attribute("nom")->value());
			}
			else if(type=="compagnie") 
			{
				currCase = new CaseCompagnie(id,
						node->first_attribute("nom")->value());
				for(int i=0;i<2;++i)
					((CaseCompagnie*)currCase)->setMultiplicateur(i, multiplicateurs_compagnies[i]);
				((CaseCompagnie*)currCase)->setPrix(prix_compagnie);
				((CaseCompagnie*)currCase)->setHypotheque(hyp_compagnie);
			}
			else if(type=="gare") 
			{
				currCase = new CaseGare(id,
						node->first_attribute("nom")->value());
				for(int i=0;i<4;++i) 
				{
					((CaseGare*)currCase)->setLoyerParGare(i, loyers_gare[i]);
				}
				((CaseGare*)currCase)->setPrix(prix_gare);
				((CaseGare*)currCase)->setHypotheque(hyp_gare);
			}
			else if(type=="depart") 
			{
				currCase = new CaseDepart(id, credit_tour);
			}
			else if(type=="prison") 
			{
				currCase = m_prison = new CasePrison(id);
			}
			else if(type=="police") 
			{
				currCase = new CaseAllerEnPrison(id);
			}
			else if(type=="parc") 
			{
				currCase = new CaseParkingGratuit(id);
			}
			else if(type=="carte") 
			{
				int id_paquet = boost::lexical_cast<int>(node->first_attribute("type")->value());
				currCase = new CaseCarte(id, m_paquets[id_paquet]);
			}
			m_case[id] = currCase;
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
void Plateau::addJoueur(Joueur *j)
{
	m_joueurs.push_back(j);
	j->positinner(m_case[0]);
	j->crediter(m_argent_depart);
}
