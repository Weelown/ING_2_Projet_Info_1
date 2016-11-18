/*
* @Author: Romain_Gérardin
* @Date:   2016-11-15 20:36:19
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-18 09:06:05
*/

#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>

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
	Case();
	Case(unsigned char _ligne, unsigned char _colone, bool _libre);

	void set_libre(bool _libre);
	bool get_libre();
};

Case::Case()
:Cordonnees(0,0),m_libre(true)
{}

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
	string m_nom;

public:
	Joueur(string _nom);
	~Joueur();
};

Joueur::Joueur(string _nom)
:m_pieces(5),m_nom(_nom)
{}

Joueur::~Joueur()
{}


void init_plateau(map<string,Case>& Init)
{
	Init["A1"] = Case('A','1',true);
	Init["A2"] = Case('A','2',true);
	Init["A3"] = Case('A','3',true);
	Init["A4"] = Case('A','4',true);
	Init["A5"] = Case('A','5',true);

	Init["B1"] = Case('B','1',true);
	Init["B2"] = Case('B','2',true);
	Init["B3"] = Case('B','3',true);
	Init["B4"] = Case('B','4',true);
	Init["B5"] = Case('B','5',true);

	Init["C1"] = Case('C','1',true);
	Init["C2"] = Case('C','2',true);
	Init["C3"] = Case('C','3',true);
	Init["C4"] = Case('C','4',true);
	Init["C5"] = Case('C','5',true);

	Init["D1"] = Case('D','1',true);
	Init["D2"] = Case('D','2',true);
	Init["D3"] = Case('D','3',true);
	Init["D4"] = Case('D','4',true);
	Init["D5"] = Case('D','5',true);

	Init["E1"] = Case('E','1',true);
	Init["E2"] = Case('E','2',true);
	Init["E3"] = Case('E','3',true);
	Init["E4"] = Case('E','4',true);
	Init["E5"] = Case('E','5',true);
}


void init_element(vector<Piece>& elem)
{
	elem.push_back(Piece(0,0,"E1",0,0,0,0));
	elem.push_back(Piece(0,0,"E2",0,0,0,0));
	elem.push_back(Piece(0,0,"E3",0,0,0,0));
	elem.push_back(Piece(0,0,"E4",0,0,0,0));
	elem.push_back(Piece(0,0,"E5",0,0,0,0));

	elem.push_back(Piece(0,0,"R1",0,0,0,0));
	elem.push_back(Piece(0,0,"R2",0,0,0,0));
	elem.push_back(Piece(0,0,"R3",0,0,0,0));
	elem.push_back(Piece(0,0,"R4",0,0,0,0));
	elem.push_back(Piece(0,0,"R5",0,0,0,0));

	elem.push_back(Piece('B',3,"M1",0.9,0.9,0.9,0.9));
	elem.push_back(Piece('C',3,"M2",0.9,0.9,0.9,0.9));
	elem.push_back(Piece('D',3,"M3",0.9,0.9,0.9,0.9));
}


int main(){

	Joueur Player_1("Mathieu"), Player_2("Léa");

	map<string,Case> Plateau;			// Déclaration des conteneurs
	vector<Piece> Element;

	init_plateau(Plateau);				// Initialisation des conteneurs
	init_element(Element);

	cout << Plateau["A4"].get_colone() << "		" << Plateau["A4"].get_ligne() << "		" << Plateau["A4"].get_libre();   // Affichage des données d'une case
	


	// string a;														Test d'affichage foireux des cases !!
	// for (unsigned char i = 'A'; i < 'F'; i++)
	// {
	// 	for (unsigned char j = 1; j < 6; j++)
	// 	{
	// 		a += i;
	// 		a += j;
	// 		cout << Plateau[a].get_colone() << "		" << Plateau[a].get_ligne() << "		" << Plateau[a].get_libre() << endl;
	// 	}
	// }




	system("pause");

    return 0;

}