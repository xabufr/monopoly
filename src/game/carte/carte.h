#ifndef _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_CARTE_CARTE_H__
#define _HOME_THOMAS_PROGRAMMATION_MONOPOLY_SRC_GAME_CARTE_CARTE_H__

#include <string>

class Joueur;
class PaquetCarte;

class Carte
{
    public:
        Carte(const std::string& descr, PaquetCarte*);
        const std::string& description() const;
        virtual void tirer(Joueur*) = 0;
        /**
            tirer : la methode change en fonction de la classe : polyumorphisme
            (+ valeur dans argent, aller à ID....)
            Il faut influer sur le comportement du joueur en fonction du type de carte
            sur laquelle il tombe
        **/
        virtual bool peutSeConserver() const;
        // prison : redefinition : true
        virtual bool estEnPossession() const;
        // sortir de prison => 1 par paquet
        PaquetCarte* paquet() const;

    protected:
        PaquetCarte* m_paquet;

    private:
        std::string m_description;
};

#endif
