#ifndef _CARTE_ALLER_EN_PRISON
#define _CARTE_ALLER_EN_PRISON
#include "carte.h"
#include <string>

class Carte_aller_en_prison : public Carte
{

    public:
        Carte_aller_en_prison(const std::string& descr, PaquetCarte* paquet);

    private:

};

#endif
