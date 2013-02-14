#ifndef CARTE_ALLER_A_RELATIF
#define CARTE_ALLER_A_RELATIF
#include "carte.h"
#include "carte_aller_a.h"
#include <string>

class Carte_aller_a_relatif : public  Carte_aller_a
{
    public:
        Carte_aller_a_relatif(int id,const std::string& descr, PaquetCarte* paquet);
    protected:
    private:
};

#endif
