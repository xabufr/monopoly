#include "carte.h"

Carte::Carte(const std::string& descr, PaquetCarte* paquet): m_description(descr), m_paquet(paquet)
{
}
const std::string& Carte::description() const
{
	return m_description;
}
bool Carte::peutSeConserver() const
{
	return false;
}
bool Carte::estEnPossession() const
{
	return false;
}
PaquetCarte* Carte::paquet() const
{
	return m_paquet;
}

