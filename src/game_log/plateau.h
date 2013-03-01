#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_PLATEAU_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_PLATEAU_H__

#include <vector>
#include <string>
#include <cstddef>

class Joueur;
class PaquetCarte;
class Case;
class CasePrison;
class Des;
class Plateau
{
public:
	Plateau();
	~Plateau();
	std::vector<Joueur*> GetJoueurs();
	void emprisoner(Joueur*);
	void liberer(Joueur*);
	Joueur* getJoueurTour() const;
	Des& getDes() const;
	void lancerDes();
	void joueurTourFinit();
	void avancerCurrentJoueur(int dep);
	void placerCurrentJoueur(int id, bool passerDepart);
	void addJoueur(Joueur*);
	void load(const std::string&);
	void save(const std::string&);
	Joueur* gagnant() const;
	int getTailleCase() const;
	int getEspaceMaison() const;
	int getTailleTraits() const;
	void payerCaution(Joueur*);
	Case* getCase(size_t) const;
private:
	int m_argent_depart;
	int m_valeur_caution;
	int m_taille_case, m_espace_maison, m_taille_traits;
	std::vector<Joueur*> m_joueurs;
	Case* m_case[40];
	PaquetCarte* m_paquets[2];
	CasePrison *m_prison;
	Des *m_des;
	size_t m_index_current_joueur;
	bool m_changer_joueur;
};

#endif
