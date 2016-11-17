/*
* @Author: Romain_Gérardin
* @Date:   2016-11-01 19:03:06
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-03 21:44:10
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

// Déclaration de la classe

class Perso
{
private:
	char m_perso;
	string m_nom;
	char m_orientation;
	float m_haut;
	float m_droite;
	float m_bas;
	float m_gauche;

public:
	Perso();
	Perso(Perso const& cop);
	Perso(char _perso, string _nom, char _orientation, float _haut, float _bas, float _gauche, float _droite);

	char get_perso();
	string get_nom();
	char get_orientation();
	float get_haut();
	float get_bas();
	float get_gauche();
	float get_droite();

	void set_perso(char _perso);
	void set_nom(string _nom);
	void set_orientation(char _orientation);
	void set_haut(float _haut);
	void set_bas(float _bas);
	void set_gauche(float _gauche);
	void set_droite(float _droite);
};


// Définition des constructeurs

	Perso::Perso()
	:m_perso('#'), m_nom("Initialisation"), m_orientation(0), m_gauche(0), m_droite(0), m_haut(0), m_bas(0)
	{}

	Perso::Perso(Perso const& copy)
	:m_perso(copy.m_perso), m_nom(copy.m_nom), m_orientation(copy.m_orientation), m_haut(copy.m_haut), m_bas(copy.m_bas), m_gauche(copy.m_gauche), m_droite(copy.m_droite)
	{}

	Perso::Perso(char _perso, string _nom, char _orientation, float _haut, float _bas, float _gauche, float _droite)
	:m_perso(_perso), m_nom(_nom), m_orientation(_orientation), m_haut(_haut), m_bas(_bas), m_droite(_droite), m_gauche(_gauche)
	{}


 // Définition des getters

	char Perso::get_perso() {return m_perso;}
	string Perso::get_nom() {return m_nom;}
	char Perso::get_orientation() {return m_orientation;}
	float Perso::get_haut() {return m_haut;}
	float Perso::get_bas() {return m_bas;}
	float Perso::get_gauche() {return m_gauche;}
	float Perso::get_droite() {return m_droite;}


// Définition des setters

	void Perso::set_perso(char _perso) {m_perso = _perso;}
	void Perso::set_nom(string _nom) {m_nom = _nom;}
	void Perso::set_orientation(char _orientation) {m_orientation = _orientation;}
	void Perso::set_haut(float _haut) {m_haut = _haut;}
	void Perso::set_bas(float _bas) {m_bas = _bas;}
	void Perso::set_gauche(float _gauche) {m_gauche = _gauche;}
	void Perso::set_droite(float _droite) {m_droite = _droite;}


// A1 A2 A3 A4 A5
// B1 B2 B3 B4 B5
// C1 C2 C3 C4 C5
// D1 D2 D3 D4 D5
// E1 E2 E3 E4 E5

void afficher_map(vector<Perso> plateau)
{
	cout << endl;

	for(int i = 0; i < 5; i++) {cout << "\t" << (char)plateau[i].get_perso();}

	cout << endl;
	cout << endl;

	for(int i = 5; i < 10; i++) {cout << "\t" << (char)plateau[i].get_perso();}

	cout << endl;
	cout << endl;

	for(int i = 10; i < 15; i++) {cout << "\t" << (char)plateau[i].get_perso();}

	cout << endl;
	cout << endl;

	for(int i = 15; i < 20; i++) {cout << "\t" << (char)plateau[i].get_perso();}

	cout << endl;
	cout << endl;

	for(int i = 20; i < 25; i++) {cout << "\t" << (char)plateau[i].get_perso();}

	cout << endl;
	cout << endl;

}

vector<Perso> init()
{
	vector<Perso> plateau;
	for(int i = 0; i < 25; i++)
	{
		plateau.push_back(Perso());
	}


	for (int i = 11; i < 14; ++i)
	{
		plateau[i].set_perso('M');
		plateau[i].set_nom("Montagne");
		plateau[i].set_orientation(0);
		plateau[i].set_gauche(0.9);
		plateau[i].set_droite(0.9);
		plateau[i].set_haut(0.9);
		plateau[i].set_bas(0.9);
	}
	return plateau;
}



int main()
{
	vector<Perso> plateau;

	plateau = init();
	
	cout << plateau[11].get_perso() << endl << plateau[11].get_nom() << endl << plateau[11].get_gauche() << endl << plateau[11].get_droite() << endl << plateau[11].get_haut() << endl << plateau[11].get_bas() << endl << endl;
	cout << plateau[1].get_perso() << endl << plateau[1].get_nom() << endl << plateau[1].get_gauche() << endl << plateau[1].get_droite() << endl << plateau[1].get_haut() << endl << plateau[1].get_bas() << endl << endl;

	// afficher_map(plateau);

	system("pause");


    return 0;
}