#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_PLATEAU_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_PLATEAU_H__

#include <vector>
class Joueur;
class Case;
class CasePrison;
class Plateau
{
public:
	void addArgent(int);
	void viderArgent();
	int getArgent() const;
	void emprisoner(Joueur*);
	void liberer(Joueur*);
	Joueur* getJoueurTour() const;
	void joueurTourFinit();
	enum EtatPlateau{
		AttenteLancerDes,
		LancerDes,
		DeplacerPion,
		AfficherOptions,
		PasserJoueurSuivant
	};
	EtatPlateau etatPlateau() const;
	void setEtatPlateau(EtatPlateau);
private:
	EtatPlateau m_etat;
	int m_argent;
	std::vector<Joueur*> m_joueurs;
	Case* m_case[40];
	CasePrison *m_prison;
	size_t m_index_current_joueur;
};

#endif 