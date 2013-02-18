#ifndef CARTE_REPARATION_H
#define CARTE_REPARATION_H
#include "carte.h"
#include <string>
#include "../joueur.h"
#include "../plateau.h"
#include "../case/case.h"
#include "../case/casecarte.h"
#include "../case/casepropriete/caseterrain.h"

class Carte_reparation : public  Carte
{
    public:
        Carte_reparation(bool hotel,int maison,const std::string& descr, PaquetCarte* paquet);
        virtual ~Carte_reparation();
        virtual void tirer(Joueur*);
    protected:
    private:
        bool m_hotel;
        int m_maison;
};

#endif // CARTE_REPARATION_H
