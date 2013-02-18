#include "caseprison.h"
#include "../joueur.h"

CasePrison::CasePrison(size_t id, const std::string& nom):Case(id, nom)
{

}

void CasePrison::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    if (j->estEnPrison())
        m_prisonnier.push_back(j);
}

void CasePrison::joueurPart(Joueur* j)
{
    Case::joueurPart(j);
    if (j->estEnPrison())
    {
        j->setPrison(false);
    }
}
