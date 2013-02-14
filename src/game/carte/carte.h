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
        virtual bool peutSeConserver() const;
        virtual bool estEnPossession() const;
        bool appartientA(Joueur*) const;
        Joueur* appartient() const;
        PaquetCarte* paquet() const;

    protected:
        PaquetCarte* m_paquet;

    private:
        std::string m_description;
};

#endif
