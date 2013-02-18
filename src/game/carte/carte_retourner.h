#ifndef CARTE_RETOURNER
#define CARTE_RETOURNER
#include "carte.h"
#include "carte_aller_a.h"
#include <string>

class Carte_retourner : public  Carte_aller_a
{
    public:
        Carte_retourner(int id,const std::string& descr, PaquetCarte* paquet);
    protected:
    private:
        int m_id;
};

#endif

