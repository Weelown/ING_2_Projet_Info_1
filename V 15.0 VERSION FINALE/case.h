#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

#include "joueur.h"
#include "cordonnees.h"
#include <string>

using namespace std;

class Case		:public Cordonnees
{
protected:
	bool m_libre;

public:
	Case();
	Case(string _coordonnees, bool _libre);

	void set_libre(bool _libre);
	bool get_libre();
};

#endif // CASE_H_INCLUDED
