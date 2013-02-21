#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_DES_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_DES_H__

#include <SFML/System.hpp>

class Des
{
public:
	Des();
	void lancer();
	int valeur() const;
	bool estDouble() const;
	int valeur(size_t) const; //Retourne la valeur du dés 0 ou 1
private:
	int m_valeur[2];
};

#endif 
