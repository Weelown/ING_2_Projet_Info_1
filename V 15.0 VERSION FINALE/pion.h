#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED


#include "joueur.h"
#include "cordonnees.h"
#include <string>
#include "case.h"
#include "piece.h"

using namespace std;

class Pion :public Piece 																	// Class Pion (Elephant / Rhinoceros)
{
public:
	Pion(string _coordonnees, float _haut, float _bas, float _gauche, float _droite);
};

class Montagne :public Piece 														// Class Montagne
{
public:
	Montagne(string _coordonnees);
};

#endif // PION_H_INCLUDED
