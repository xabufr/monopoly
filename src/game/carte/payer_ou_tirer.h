#ifndef PAYER_OU_TIRER
#define PAYER_OU_TIRER
#include "carte.h"
#include "carte_argent.h"
#include <string>

class Payer_ou_tirer : public  Carte_argent
{
    public:
        Payer_ou_tirer(int type,int val,const std::string& descr, PaquetCarte* paquet);
    protected:
    private:
        int m_type;
};

#endif

