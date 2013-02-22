#ifndef _CARTE_LIBERE
#define _CARTE_LIBERE
#include "carte.h"
#include <string>

// libere de prison
class Carte_Libere : public Carte
{

    public:
        Carte_Libere(const std::string& descr, PaquetCarte* paquet);
        // delete, + sort de prison.
        virtual void tirer(Joueur*);

        virtual bool peutSeConserver() const;
        // prison : redefinition : true
        virtual bool estEnPossession() const;
        // sortir de prison => 1 par paquet;

    private:

};

#endif
