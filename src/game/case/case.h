#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_CASE_CASE_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_CASE_CASE_H__

#include <string>
#include <list>

class Joueur;
class Case
{
public:
	Case(size_t id, const std::string& nom);
	const std::string& nom() const;
	virtual void joueurArrive(Joueur*);
	virtual void joueurPart(Joueur*);
	virtual void joueurPasse(Joueur*);
	virtual bool peutAppartenir() const;
	const std::list<Joueur*>& getJoueurs() const;
	size_t id() const;
private:
	std::string m_nom;
	std::list<Joueur*> m_joueurs;
	size_t m_id;
};

#endif
