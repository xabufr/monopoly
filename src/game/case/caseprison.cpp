#include "caseprison.h"
#include "../joueur.h"

CasePrison::CasePrison(size_t id, const std::string& nom):Case(id, nom)
{

}

void CasePrison::joueurArrive(Joueur*)
{
    Case::joueurArrive(j);
    if (j->estEnPrison())
        m_prisonnier.push_back(j);
}

void CasePrison::joueurPart(Joueur*)
{
    Case::joueurPart(j);
    if (j->estEnPrison())
    {
        m_prisonnier.pop_back(j);
        j->setPrison(false);
    }
}
