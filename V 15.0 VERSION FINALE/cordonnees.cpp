#include "cordonnees.h"

using namespace std;

Cordonnees::Cordonnees()
:m_coordonnees("00")
{}

Cordonnees::Cordonnees(string _coordonnees)
:m_coordonnees(_coordonnees)
{}

Cordonnees::~Cordonnees()
{}
void Cordonnees::set_coordonnees(string _coordonnees) {m_coordonnees = _coordonnees;}

string Cordonnees::get_coordonnees() {return m_coordonnees;}
