#ifndef PAYER_OU_TIRER
#define PAYER_OU_TIRER
#include "carte.h"
#include "carte_argent.h"
#include <string>
#include <iostream>

class Payer_ou_tirer : public  Carte_argent
{
    public:
        Payer_ou_tirer(int val,const std::string& descr, PaquetCarte* paquet_source, PaquetCarte* paquet_cible);
        virtual void tirer(Joueur*);
    protected:
    private:
        bool veut_payer();
        // true = payer
        PaquetCarte* m_paquet_cible;
        bool m_choix;
        // type : type du paquet a recuperer
        // recupere le choix : paye ou tire ??
        // si paye : paye
        // si tire =>
};

#endif

