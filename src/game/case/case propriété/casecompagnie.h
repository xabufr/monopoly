#ifndef CASECOMPAGNIE_H_INCLUDED
#define CASECOMPAGNIE_H_INCLUDED

#include "case.h"

class Joueur;
class CaseCompagnie : public Case
{
public:
	CaseCompagnie(size_t id, const std::string& nom);
	virtual void joueurArrive(Joueur*);
	virtual void joueurPart(Joueur*);
	virtual void joueurPasse(Joueur*);
	virtual bool peutAppartenir() const;
	virtual bool peutAcheter(const Joueur*) const;
	virtual void acheter(Joueur*);

	virtual int prixAchat() const;
	virtual bool estAchete() const;
	virtual void acheter(Joueur*);
	virtual int valeur_hypotheque() const;
    virtual void hypothequer();
    virtual bool estEnHypotheque() const;
    virtual int loyer() const;
    virtual bool peutConstruire() const;
private:
    static int m_multiplicateur[2];

#endif // CASECOMPAGNIE_H_INCLUDED
