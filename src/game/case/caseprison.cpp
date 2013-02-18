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
        for(auto it=m_prisonnier.begin(); it!=m_prisonnier.end();++it)
        {
            if((*it)==j)
            {
                m_prisonnier.erase(it);
                j->setPrison(false);
                return;
            }
        }
    }
}
