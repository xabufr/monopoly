#ifndef CARTE_REPARATION_H
#define CARTE_REPARATION_H
#include "src/game/carte/carte.h"
#include <string>

class Carte_reparation : public  Carte
{
    public:
        Carte_reparation(bool hotel,int maison);
        virtual ~Carte_reparation();
    protected:
    private:
        bool m_hotel;
        int m_maison;
};

#endif // CARTE_REPARATION_H
