#include "casecarte.h"
#include "../joueur.h"
#include "../carte/carte.h"
#include "../carte/paquet.h"
#include "../carte/carteliberte.h"

CaseCarte::CaseCarte(size_t id, const std::string& nom):Case(id, nom)
{

}

void CaseCarte::joueurArrive(Joueur* j)
{
    Case::joueurArrive(j);
    Carte *carte = m_paquet->tirer();
    if (dynamic_cast<CarteLiberte*>(carte) != 0)
        j->addCarteLiberte((CarteLiberte*)carte);
}

void CaseCarte::setPaquet(PaquetCarte* p)
{
    m_paquet = p;
}
