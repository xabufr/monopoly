#include "caseallerenprison.h"
#include "../joueur.h"

CaseAllerEnPrison::CaseAllerEnPrison(size_t id):Case(id, "Allez en prison")
{

}
void CaseAllerEnPrison::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    j->setPrison(true);
}
