#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_CARTE_PAQUET_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_CARTE_PAQUET_H__

#include <list>
#include <string>

class Carte;
class Plateau;
class PaquetCarte
{
public:
	PaquetCarte(int type, const std::string& nom, const std::string& logo, Plateau*);
	~PaquetCarte();
	int type() const;
	const std::string& nom() const;
	const std::list<Carte*>& cartes() const;
	const std::string& cheminLogo() const;
	Carte* tirer();
	Plateau* plateau() const;
	void ajouterCarte(Carte*);
	void melanger();
private:
	std::list<Carte*> m_cartes;
	std::string m_nom, m_chemin_logo;
	int m_type;
	Plateau *m_plateau;
};

#endif
