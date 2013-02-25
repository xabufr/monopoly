#include "des.h"
#include "../core/random.h"

Des::Des()
{
}
void Des::lancer()
{
	m_valeur[0] = Random::Rand(1,7);
	m_valeur[1] = Random::Rand(1,7);
}
int Des::valeur() const
{
	return m_valeur[0]+m_valeur[1];
}
int Des::valeur(int i) const
{
	return m_valeur[i];
}
int Des::valeur(size_t de) const
{
	return m_valeur[de];
}
bool Des::estDouble() const
{
	return m_valeur[0]==m_valeur[1];
}
