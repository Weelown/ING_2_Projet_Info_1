#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "joueur.h"
#include "cordonnees.h"
#include <string>
#include "case.h"

using namespace std;

class Piece     :public Cordonnees              // Class Piece
{
protected:
	float m_haut;
	float m_bas;
	float m_gauche;
	float m_droite;

public:
	Piece(string _coordonnees, float _haut, float _bas, float _gauche, float _droite);

	void set_haut(float _haut);
	void set_bas(float _bas);
	void set_gauche(float _gauche);
	void set_droite(float _droite);

	float get_haut();
	float get_bas();
	float get_gauche();
	float get_droite();
};


#endif // PIECE_H_INCLUDED
