#include "des.h"
#include "../core/random.h"

Des::Des()
{
}
void Des::lancer()
{
	m_valeur[0] = Random::Rand(1,6);
	m_valeur[1] = Random::Rand(1,6);
}
int Des::valeur() const
{
	return m_valeur[0]+m_valeur[1];
}
int Des::valeur(size_t de) const
{
	return m_valeur[de];
}
bool Des::estDouble() const
{
	return m_valeur[0]==m_valeur[1];
}
