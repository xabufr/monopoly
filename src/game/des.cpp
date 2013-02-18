#include "des.h"
#include "../core/random.h"

Des::Des()
{
	m_lancerEnCours = false;
	m_temps_lancer  = 1500;
}
void Des::lancer()
{
	m_lancerEnCours = true;
	m_timer_lancer.restart();
}
bool Des::estEnTrainDeLancer()
{
	if(m_lancerEnCours&&m_timer_lancer.getElapsedTime().asMilliseconds() >= m_temps_lancer)
	{
		m_lancerEnCours=false;
		m_valeur[0] = Random::Rand(1,6);
		m_valeur[1] = Random::Rand(1,6);
	}
	return m_lancerEnCours;
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
