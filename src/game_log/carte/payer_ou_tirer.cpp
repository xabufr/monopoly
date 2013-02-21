#include "payer_ou_tirer.h"
#include "paquet.h"
#include "../joueur.h"

Payer_ou_tirer::Payer_ou_tirer(int val,const std::string& descr, PaquetCarte* paquet_source, PaquetCarte* paquet_cible)
: Carte_argent( val, descr, paquet_source)
, m_paquet_cible (paquet_cible)
{

}

void Payer_ou_tirer::tirer(Joueur* j)
{
    if (veut_payer() == true) // pour l'instant : on a pas de moyen de savoir si le joueur veut payer
    {
        if(m_valeur > 0)
        {
            j->crediter(m_valeur);
        }
        else
        {
            j->payer(m_valeur);
        }
    }
    else
    {
        m_paquet_cible->tirer();
    }
}

bool Payer_ou_tirer::veut_payer()
{
    char str [1];
    do
    {
        std::cout << "Voulez-vous (P)ayer ou (T)irer ?" << std::endl;
        scanf ("%s",str);
    }while((str != "p") || (str!="t"));

    if (str == "p")
        return true;
    else
        return false;

}





