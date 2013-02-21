#include "carte_argent_depuis_joueur.h"

Carte_argent_depuis_joueur::Carte_argent_depuis_joueur(int val,const std::string& descr, PaquetCarte* paquet)
: Carte_argent(val,descr,paquet)
{

}

void Carte_argent_depuis_joueur::tirer(Joueur* j)
{

    Plateau* temp_plateau = m_paquet->plateau();
    std::vector<Joueur*> temp_joueurs = temp_plateau->GetJoueurs();

    for (int i = 0;i<temp_joueurs.size();i++)
    {
        if(j != temp_joueurs[i])
        {
            temp_joueurs[i]->payer(m_valeur);
            j->crediter(m_valeur);
        }
    }

}
