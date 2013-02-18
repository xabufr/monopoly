#include "carte_reparation.h"

Carte_reparation::Carte_reparation(bool hotel,int maison,const std::string& descr, PaquetCarte* paquet)
: Carte(descr, paquet)
, m_hotel(hotel)
, m_maison(maison)
{

}
Carte_reparation::~Carte_reparation()
{
    delete this;
}
void Carte_reparation::tirer(Joueur* j)
{
    std::list<CasePropriete*> MesProprietes = j->proprietes();
    for(std::list<CasePropriete*>::iterator it = MesProprietes.begin(); it!=MesProprietes.end();it++)
    {
        CaseTerrain* CaseContent;
        if ((CaseContent == dynamic_cast<CaseTerrain*>(*it)) != 0)
        {
            if(CaseContent->maisons() < 5)
            {
                j->payer(CaseContent->maisons() * m_maison);
                break;
            }
            else
                j->payer(m_hotel);
        }
    }
}


