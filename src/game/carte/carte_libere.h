#ifndef _CARTE_LIBERE
#define _CARTE_LIBERE
#include "carte.h"
#include <string>

class Carte_Libere : public Carte
{

    public:
        Carte_Libere(const std::string& descr, PaquetCarte* paquet);
        void utiliser();

    private:

};

#endif
