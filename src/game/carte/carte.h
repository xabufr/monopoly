#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_CARTE_CARTE_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_CARTE_CARTE_H__

class Joueur;
class PaquetCarte;
class Carte
{
public:
	const std::string& description() const;
	void tirer(Joueur*);
	virtual bool peutSeConserver() const;
	virtual bool estEnPossession() const;
	bool appartientA(Joueur*) const;
	Joueur* appartient() const;
	PaquetCarte* paquet() const;

protected:
	PaquetCarte* m_paquet;

private:
	std::string m_description;
};

#endif 
