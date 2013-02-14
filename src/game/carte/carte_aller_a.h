#ifndef CARTE_ALLER_A
#define CARTE_ALLER_A
#include "carte.h"
#include <string>

class Carte_aller_a : public  Carte
{
    public:
        Carte_aller_a(int id, const std::string& descr, PaquetCarte* paquet);
    protected:
    private:
        int m_id;
};

#endif
