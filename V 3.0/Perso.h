#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;

// Déclaration de la classe (prototypes)

class Perso
{
private:
	char m_perso;  		// Attributs
	string m_nom;
	char m_orientation;
	float m_haut;
	float m_droite;
	float m_bas;
	float m_gauche;

public:
	Perso();					// Constructeurs
	Perso(Perso const& cop);
	Perso(char _perso, string _nom, char _orientation, float _haut, float _bas, float _gauche, float _droite);

	char get_perso();			// Getters
	string get_nom();
	char get_orientation();
	float get_haut();
	float get_bas();
	float get_gauche();
	float get_droite();

	void set_perso(char _perso);		// Setters
	void set_nom(string _nom);
	void set_orientation(char _orientation);
	void set_haut(float _haut);
	void set_bas(float _bas);
	void set_gauche(float _gauche);
	void set_droite(float _droite);


										// Procédure d'affichage de tous les détails d'un objet
	void affichage_details_perso();
};

#endif
