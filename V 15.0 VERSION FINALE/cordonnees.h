#ifndef CORDONNEES_H_INCLUDED
#define CORDONNEES_H_INCLUDED


#include <string>
#include <cstdio>
#include <cstdlib>
#include "joueur.h"

using namespace std;

class Cordonnees												// Class Cordonnees
{
protected:
	string m_coordonnees
;
public:
	Cordonnees();
	Cordonnees(string _coordonnees);
	~Cordonnees();

	void set_coordonnees(string _coordonnees);

	string get_coordonnees();
};


#endif // CORDONNEES_H_INCLUDED
