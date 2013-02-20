#include "case.h"

Case::Case(size_t id, const std::string& nom): m_id(id), m_nom(nom)
{
}
const std::string& Case::nom() const
{
	return m_nom;
}
void Case::joueurArrive(Joueur* j)
{
	m_joueurs.push_back(j);
}
void Case::joueurPart(Joueur* j_partant)
{
	for(auto it=m_joueurs.begin(); it!=m_joueurs.end();++it)
	{
		if((*it)==j_partant)
		{
			m_joueurs.erase(it);
			return;
		}
	}
}
void Case::joueurPasse(Joueur*)
{
}
bool Case::peutAppartenir() const
{
	return false;
}

const std::list<Joueur*>& Case::getJoueurs() const
{
	return m_joueurs;
}

size_t Case::id() const
{
	return m_id;
}
int Case::prixAchat() const
{
    return 0;
}

bool Case::estAchete() const
{
    return false;
}

void Case::acheter(Joueur*)
{

}

int Case::valeur_hypotheque() const
{
    return 0;
}

void Case::hypothequer()
{

}

void Case::deshypothequer()
{

}

bool Case::estEnHypotheque() const
{
    return false;
}

int Case::loyer() const
{
    return 0;
}

bool Case::peutConstruire() const
{
    return false;
}


