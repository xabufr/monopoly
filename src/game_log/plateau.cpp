#include "plateau.h"
#include "joueur.h"
#include "des.h"
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
#include "case/casepropriete/casepropriete.h"
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
#include <utility>
#include <boost/lexical_cast.hpp>

Plateau::Plateau()
{
    m_des = new Des;
    m_index_current_joueur = 0;
	std::ifstream file;
	file.open("config.xml");
	if(!file)
	{
		std::cerr << "Fichier config.xml manquant" << std::endl;
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
	m_taille_case   = boost::lexical_cast<int>(root->first_node("plateau")->first_attribute("taille_case")->value());
	m_espace_maison = boost::lexical_cast<int>(root->first_node("plateau")->first_attribute("espace_maison")->value());
	m_taille_traits = boost::lexical_cast<int>(root->first_node("plateau")->first_attribute("taille_traits")->value());

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
			if(carte)
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
				m_case[id] = terrain;
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
				currCase = new CaseAllerEnPrison(id, this);
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
Plateau::~Plateau()
{
	for (size_t i = 0; i < 40; ++i)
	{
		delete m_case[i];
	}
	for (size_t i = 0; i < 2; ++i)
	{
		delete m_paquets[i];
	}
	for(Joueur *j : m_joueurs)
	{
		delete j;
	}
	delete m_des;
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
	if(dep>0)
	{
		for(int i=0;i<dep-1;++i)
		{
			if(++curPos==40)
				curPos=0;
			m_case[curPos]->joueurPasse(j);
		}
		if(++curPos==40)
			curPos=0;
	}
	else
	{
		for(int i=0;i < (-dep);++i) 
		{
			std::cout << i << std::endl;
			if(curPos==0)
				curPos = 39;
			else
				--curPos;
		}
	}
	j->positinner(m_case[curPos]);
	m_case[curPos]->joueurArrive(j);
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
void Plateau::load(const std::string& filepath)
{
	std::ifstream file;
	file.open(filepath.c_str());
	if(!file)
	{
		std::cerr << "Le fichier de sauvegarde n'existe pas" << std::endl;
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
	rapidxml::xml_node<> *root = document.first_node("root");
	rapidxml::xml_node<> *node;
	for(node=root->first_node("joueurs")->first_node("joueur");node;node=node->next_sibling("joueur"))
	{
		Joueur *joueur = new Joueur(node->first_attribute("nom")->value());
		m_joueurs.push_back(joueur);
		joueur->crediter(boost::lexical_cast<int>(node->first_attribute("argent")->value()));
		int idCase = boost::lexical_cast<int>(node->first_attribute("case")->value());
		joueur->positinner(m_case[idCase]);
		m_case[idCase]->joueurArrive(joueur);
		if(boost::lexical_cast<bool>(node->first_attribute("prison")->value()))
			emprisoner(joueur);
		rapidxml::xml_node<> *nodeProp;
		rapidxml::xml_node<> *nodeCartes;
		for(nodeCartes=node->first_node("cartes")->first_node("carte");nodeCartes;nodeCartes=nodeCartes->next_sibling("carte"))
		{
			int paq = boost::lexical_cast<int>(nodeCartes->first_attribute("paquet")->value());
			for(Carte *carte : m_paquets[paq]->cartes())
			{
				Carte_Libere *lib = dynamic_cast<Carte_Libere*>(carte);
				if(lib)
				{
					lib->tirer(joueur);
					break;
				}
			}
		}
		for(nodeProp=node->first_node("propriete");nodeProp;nodeProp=nodeProp->next_sibling("propriete"))
		{
			CasePropriete *prop = (CasePropriete*) m_case[boost::lexical_cast<int>(nodeProp->first_attribute("id")->value())];
			prop->setProprietaire(joueur);
			joueur->addPropriete(prop);
			if(boost::lexical_cast<bool>(nodeProp->first_attribute("hypotheque")->value()))
				prop->hypothequer(false);
			CaseTerrain *terrain = dynamic_cast<CaseTerrain*>(prop);
			if(terrain)
			{
				terrain->setMaisons(boost::lexical_cast<int>(nodeProp->first_attribute("maisons")->value()));
			}
		}
	}
	m_index_current_joueur = boost::lexical_cast<int>(root->first_node("joueurs")->first_attribute("current")->value());
}
void Plateau::save(const std::string& file)
{
	rapidxml::xml_document<> document;
	rapidxml::xml_node<> *root = document.allocate_node(rapidxml::node_type::node_element);
	root->name("root");
	document.append_node(root);
	rapidxml::xml_node<> *nJoueurs = document.allocate_node(rapidxml::node_type::node_element);
	nJoueurs->name("joueurs");
	root->append_node(nJoueurs);
	for(Joueur *j : m_joueurs)
	{
		rapidxml::xml_node<> *nJoueur = document.allocate_node(rapidxml::node_type::node_element);
		nJoueur->name("joueur");
		nJoueur->append_attribute(document.allocate_attribute("nom", j->nom().c_str()));
		nJoueur->append_attribute(document.allocate_attribute("case", boost::lexical_cast<std::string>(j->estSur()->id()).c_str()));
		nJoueur->append_attribute(document.allocate_attribute("prison", boost::lexical_cast<std::string>(j->estEnPrison()).c_str()));
		nJoueur->append_attribute(document.allocate_attribute("argent", boost::lexical_cast<std::string>(j->argent()).c_str()));
		nJoueurs->append_node(nJoueur);
		rapidxml::xml_node<> *nCartes = document.allocate_node(rapidxml::node_type::node_element);
		nCartes->name("cartes");
		nJoueur->append_node(nCartes);
		for(Carte_Libere *c : j->cartesLiberte())
		{
			rapidxml::xml_node<> *nCarte = document.allocate_node(rapidxml::node_type::node_element);
			nCarte->name("carte");
			nCarte->append_attribute(document.allocate_attribute("paquet", boost::lexical_cast<std::string>(c->paquet()->type()).c_str()));
			nCartes->append_node(nCarte);
		}
		rapidxml::xml_node<> *nProprietes = document.allocate_node(rapidxml::node_type::node_element);
		nJoueur->append_node(nProprietes);
		for(CasePropriete *prop : j->proprietes())
		{
			rapidxml::xml_node<> *nPropriete = document.allocate_node(rapidxml::node_type::node_element);
			nProprietes->append_node(nPropriete);
			nPropriete->append_attribute(document.allocate_attribute("id", boost::lexical_cast<std::string>(prop->id()).c_str()));
			nPropriete->append_attribute(document.allocate_attribute("hypotheque", boost::lexical_cast<std::string>(prop->estEnHypotheque()).c_str()));
			CaseTerrain *terrain = dynamic_cast<CaseTerrain*>(prop);
			if(terrain)
			{
				nPropriete->append_attribute(document.allocate_attribute("maisons", boost::lexical_cast<std::string>(terrain->maisons()).c_str()));
			}
		}
	}
}
int Plateau::getTailleCase() const
{
	return m_taille_case;
}
int Plateau::getEspaceMaison() const
{
	return m_espace_maison;
}
int Plateau::getTailleTraits() const
{
	return m_taille_traits;
}
Case* Plateau::getCase(size_t id) const
{
	return (id<40) ?m_case[id]:nullptr;
}
Des& Plateau::getDes() const
{
    return *m_des;
}
