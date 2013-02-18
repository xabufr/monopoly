#ifndef CARTE_ARGENT_DEPUIS_JOUEUR
#define CARTE_ARGENT_DEPUIS_JOUEUR
#include "carte.h"
#include "carte_argent.h"
#include <string>
#include "../plateau.h"
#include "paquet.h"
#include "../joueur.h"

class Carte_argent_depuis_joueur : public  Carte_argent
{
    public:
        Carte_argent_depuis_joueur(int val,const std::string& descr, PaquetCarte* paquet);
        virtual void tirer(Joueur*);
    protected:
    private:
};

#endif

