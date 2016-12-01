#include "pion.h"

using namespace std;

Pion::Pion(string _coordonnees, float _haut, float _bas, float _gauche, float _droite)
:Piece(_coordonnees,_haut,_bas,_gauche,_droite)
{}

Montagne::Montagne(string _coordonnees)
:Piece(_coordonnees,0.9,0.9,0.9,0.9)
{}
