#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Joueur						// Class Joueur
{
private:
	int m_coup;
	string m_nom;

public:
	Joueur(string _nom);
	~Joueur();

	int get_coup();
	void set_coup(int _coup);

	string get_nom();
};




#endif // JOUEUR_H_INCLUDED
