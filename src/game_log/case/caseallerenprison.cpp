#include "caseallerenprison.h"
#include "../joueur.h"
#include "../plateau.h" 

CaseAllerEnPrison::CaseAllerEnPrison(size_t id, Plateau *p):Case(id, "Allez en prison"), m_plateau(p)
{

}
void CaseAllerEnPrison::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
	m_plateau->emprisoner(j);
}
