#include "caseallerenprison.h"
#include "../joueur.h"

CaseAllerEnPrison::CaseAllerEnPrison(size_t id, const std::string& nom):Case(id, nom)
{
	
}
void CaseAllerEnPrison::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    j->setPrison(true);
}
