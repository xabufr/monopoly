#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_PLATEAU_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_PLATEAU_H__

#include <vector>
#include <string>
#include <cstddef>

class Joueur;
class PaquetCarte;
class Case;
class CasePrison;
class Plateau
{
public:
	Plateau();
	~Plateau();
	void addArgent(int);
	void viderArgent();
	std::vector<Joueur*> GetJoueurs();
	int getArgent() const;
	void emprisoner(Joueur*);
	void liberer(Joueur*);
	Joueur* getJoueurTour() const;
	void joueurTourFinit();
	void avancerCurrentJoueur(int dep);
	void placerCurrentJoueur(int id, bool passerDepart);
	void addJoueur(Joueur*);
	void load(const std::string&);
	void save(const std::string&);

	int getTailleCase() const;
private:
	int m_argent;
	int m_argent_depart;
	int m_taille_case;
	std::vector<Joueur*> m_joueurs;
	Case* m_case[40];
	PaquetCarte* m_paquets[2];
	CasePrison *m_prison;
	size_t m_index_current_joueur;
};

#endif
