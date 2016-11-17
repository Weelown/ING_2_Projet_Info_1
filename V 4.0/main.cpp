/*
* @Author: Romain_Gérardin
* @Date:   2016-11-15 20:36:19
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-17 20:31:01
*/

#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Cordonnees												// Class Cordonnees
{
protected: 
	unsigned char m_ligne;
	unsigned char m_colone;

public:
	Cordonnees();
	Cordonnees(unsigned char _ligne, unsigned char _colone);
	~Cordonnees();

	void set_ligne(unsigned char _ligne);
	void set_colone(unsigned char _colone);

	unsigned char get_ligne();
	unsigned char get_colone();
};

Cordonnees::Cordonnees()
:m_ligne(0),m_colone(0)
{}

Cordonnees::Cordonnees(unsigned char _colone, unsigned char _ligne)
:m_ligne(_ligne),m_colone(_colone)
{}

Cordonnees::~Cordonnees()
{}
void Cordonnees::set_ligne(unsigned char _ligne) {m_ligne = _ligne;}
void Cordonnees::set_colone(unsigned char _colone) {m_colone = _colone;}

unsigned char Cordonnees::get_ligne() {return m_ligne;}
unsigned char Cordonnees::get_colone() {return m_colone;}


class Case		:public Cordonnees
{
protected:
	bool m_libre;

public:
	Case(unsigned char _ligne, unsigned char _colone, bool _libre);

	void set_libre(bool _libre);
	bool get_libre();
};

Case::Case(unsigned char _ligne, unsigned char _colone, bool _libre)
:Cordonnees(_ligne,_colone),m_libre(_libre)
{}

void Case::set_libre(bool _libre) {m_libre = _libre;}
bool Case::get_libre() {return m_libre;}


class Piece     :public Cordonnees              // Class Piece 
{
protected:
	string m_nom;
	float m_haut;
	float m_bas;
	float m_gauche;
	float m_droite;

public:
	Piece(unsigned char _ligne, unsigned char _colone, string _nom,float _haut, float _bas, float _gauche, float _droite);

	void set_haut(float _haut);
	void set_bas(float _bas);
	void set_gauche(float _gauche);
	void set_droite(float _droite);
	void set_nom(string _nom);

	float get_haut();
	float get_bas();
	float get_gauche();
	float get_droite();
	string get_nom();
};

Piece::Piece(unsigned char _ligne, unsigned char _colone, string _nom,float _haut, float _bas, float _gauche, float _droite)
:Cordonnees(_ligne,_colone),m_nom(_nom),m_haut(_haut),m_bas(_bas),m_gauche(_gauche),m_droite(_droite)
{}

float Piece::get_haut() {return m_haut;}
float Piece::get_bas() {return m_bas;}
float Piece::get_gauche() {return m_gauche;}
float Piece::get_droite() {return m_droite;}
string Piece::get_nom() {return m_nom;}

void Piece::set_haut(float _haut) {m_haut = _haut;}
void Piece::set_bas(float _bas) {m_bas = _bas;}
void Piece::set_gauche(float _gauche) {m_gauche = _gauche;}
void Piece::set_droite(float _droite) {m_droite = _droite;}
void Piece::set_nom(string _nom) {m_nom = _nom;}



class Pion :public Piece 																	// Class Pion (Elephant / Rhinocéros)
{
public:
	Pion(unsigned char _ligne, unsigned char _colone, string _nom, float _haut, float _bas, float _gauche, float _droite);
};

Pion::Pion(unsigned char _ligne, unsigned char _colone, string _nom, float _haut, float _bas, float _gauche, float _droite)
:Piece(_ligne, _colone,_nom,_haut,_bas,_gauche,_droite)
{}





class Montagne :public Piece 														// Class Montagne
{
public:
	Montagne();
};

Montagne::Montagne()
:Piece('0','0',"Montagne",0.9,0.9,0.9,0.9)
{}





class Joueur						// Class Joueur
{
private:
	unsigned char m_pieces;

public:
	Joueur();
};

Joueur::Joueur()
:m_pieces(5)
{}


/*void init_plateau(map<string,Case>& Plateau)
{
	Plateau["A1"] = Case('A','1',true);
	Plateau["A2"] = Case('A','2',true);
	Plateau["A3"] = Case('A','3',true);
	Plateau["A4"] = Case('A','4',true);
	Plateau["A5"] = Case('A','5',true);

	Plateau["B1"] = Case('B','1',true);
	Plateau["B2"] = Case('B','2',true);
	Plateau["B3"] = Case('B','3',true);
	Plateau["B4"] = Case('B','4',true);
	Plateau["B5"] = Case('B','5',true);

	Plateau["C1"] = Case('C','1',true);
	Plateau["C2"] = Case('C','2',true);
	Plateau["C3"] = Case('C','3',true);
	Plateau["C4"] = Case('C','4',true);
	Plateau["C5"] = Case('C','5',true);

	Plateau["D1"] = Case('D','1',true);
	Plateau["D2"] = Case('D','2',true);
	Plateau["D3"] = Case('D','3',true);
	Plateau["D4"] = Case('D','4',true);
	Plateau["D5"] = Case('D','5',true);

	Plateau["E1"] = Case('E','1',true);
	Plateau["E2"] = Case('E','2',true);
	Plateau["E3"] = Case('E','3',true);
	Plateau["E4"] = Case('E','4',true);
	Plateau["e5"] = Case('E','5',true);
}*/

int main(){

	Joueur Player_1(), Player_2();
	// map<int,Case> test;
	//test[1] = Montagne();
//	map<string, Case> Plateau;

//	init_plateau(Plateau);

//	system("pause");
    return 0;

}