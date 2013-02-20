#ifndef CARTE_ALLER_A
#define CARTE_ALLER_A
#include "carte.h"
#include <string>
#include "../joueur.h"

class Carte_aller_a : public  Carte
{
    public:
        Carte_aller_a(int id, const std::string& descr, PaquetCarte* paquet);
        virtual void tirer(Joueur*);
    protected:
        int m_id;
    private:
};

#endif
