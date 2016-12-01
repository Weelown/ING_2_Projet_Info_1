#include "joueur.h"

using namespace std;

Joueur::Joueur(string _nom)
:m_coup(5),m_nom(_nom)
{}

Joueur::~Joueur()
{}

int Joueur::get_coup() {return m_coup;}
void Joueur::set_coup(int _coup) {m_coup = _coup;}
string Joueur::get_nom() {return m_nom;}
