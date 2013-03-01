#ifndef PAYER_OU_TIRER
#define PAYER_OU_TIRER
#include "carte.h"
#include "carte_argent.h"
#include <string>
#include <iostream>

class Payer_ou_tirer : public  Carte_argent
{
    public:
        Payer_ou_tirer(int val,const std::string& descr, PaquetCarte* paquet_source, PaquetCarte* paquet_cible);
		void setPaquetAutre(PaquetCarte*);
		PaquetCarte* paquetAutre() const;
    private:
        PaquetCarte* m_paquet_cible;
};

#endif

