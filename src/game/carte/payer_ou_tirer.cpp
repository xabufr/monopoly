#include "payer_ou_tirer.h"

Payer_ou_tirer::Payer_ou_tirer(int type,int val,const std::string& descr, PaquetCarte* paquet)
: Carte_argent( val, descr, paquet)
, m_type (type)
{

}

