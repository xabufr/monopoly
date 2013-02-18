#ifndef _CARTE_LIBERE
#define _CARTE_LIBERE
#include "carte.h"
#include <string>

// libere de prison
class Carte_Libere : public Carte
{

    public:
        Carte_Libere(const std::string& descr, PaquetCarte* paquet);
        void utiliser();
        // delete, + sort de prison.

    private:

};

#endif
