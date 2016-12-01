#include "piece.h"

using namespace std;

Piece::Piece(string _coordonnees, float _haut, float _bas, float _gauche, float _droite)
:Cordonnees(_coordonnees),m_haut(_haut),m_bas(_bas),m_gauche(_gauche),m_droite(_droite)
{}

float Piece::get_haut() {return m_haut;}
float Piece::get_bas() {return m_bas;}
float Piece::get_gauche() {return m_gauche;}
float Piece::get_droite() {return m_droite;}

void Piece::set_haut(float _haut) {m_haut = _haut;}
void Piece::set_bas(float _bas) {m_bas = _bas;}
void Piece::set_gauche(float _gauche) {m_gauche = _gauche;}
void Piece::set_droite(float _droite) {m_droite = _droite;}
