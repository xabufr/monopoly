#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_JOUEUR_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_JOUEUR_H__

#include <string>
#include <list>

class CasePropriete;
class Case;
class Carte_Libere;
class Joueur
{
public:
	const std::string& nom() const;
	int argent() const;
	bool estFauche() const;
	void payer(int);
	void crediter(int);
	int dernierLancer() const;
	void setDernierLancer(int);
	void setPrison(bool);
	bool estEnPrison() const;
	void ajouterTourPrison();
	int getToursPrison() const;
	int getNombreGare() const;
	int getNombreCompagnie() const;
	Case* estSur() const;
	void positinner(Case*);
    void addCarteLiberte(Carte_Libere*);
    // UseCarteLibere
    /*
    void Joueur::utiliserCarteLiberte(Joueur* j, paquet* paquet)
    {
         Plateau* temp_plateau = paquet->plateau();
         temp_plateau->liberer(j);
    }
    */
    void addPropriete(CasePropriete*);
	const std::list<CasePropriete*>& proprietes() const;
private:
	int m_argent;
	std::string m_nom;
	bool m_prisonier;
	int m_tours_prison;
	int m_doubles_consecutifs;
	int m_dernier_lancer;
	std::list<CasePropriete*> m_proprietes;
	std::list<Carte_Libere*> m_cartes_liberte;
	Case *m_CasePosition;
};

#endif
