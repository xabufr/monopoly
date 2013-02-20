#ifndef CARTE_ARGENT
#define CARTE_ARGENT
#include "carte.h"
#include <string>

class Carte_argent : public  Carte
{
    public:
        Carte_argent(int val,const std::string& descr, PaquetCarte* paquet);
        virtual void tirer(Joueur*);
    protected:
        int m_valeur;
    private:
};

#endif

