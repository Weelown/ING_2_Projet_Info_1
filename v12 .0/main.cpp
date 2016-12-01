/*
* @Author: Romain_Gerardin
* @Date:   2016-11-15 20:36:19
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-30 11:22:08
*/

#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "console.h"

using namespace std;

class Cordonnees												// Class Cordonnees
{
protected: 
	string m_coordonnees
;
public:
	Cordonnees();
	Cordonnees(string _coordonnees);
	~Cordonnees();

	void set_coordonnees(string _coordonnees);

	string get_coordonnees();
};

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




class Case		:public Cordonnees
{
protected:
	bool m_libre;

public:
	Case();
	Case(string _coordonnees, bool _libre);

	void set_libre(bool _libre);
	bool get_libre();
};

Case::Case()
:Cordonnees("00"),m_libre(true)
{}

Case::Case(string _coordonnees, bool _libre)
:Cordonnees(_coordonnees),m_libre(_libre)
{}

void Case::set_libre(bool _libre) {m_libre = _libre;}
bool Case::get_libre() {return m_libre;}




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



class Pion :public Piece 																	// Class Pion (Elephant / Rhinoceros)
{
public:
	Pion(string _coordonnees, float _haut, float _bas, float _gauche, float _droite);
};

Pion::Pion(string _coordonnees, float _haut, float _bas, float _gauche, float _droite)
:Piece(_coordonnees,_haut,_bas,_gauche,_droite)
{}



class Montagne :public Piece 														// Class Montagne
{
public:
	Montagne(string _coordonnees);
};

Montagne::Montagne(string _coordonnees)
:Piece(_coordonnees,0.9,0.9,0.9,0.9)
{}





class Joueur						// Class Joueur
{
private:
	int m_coup;
	string m_nom;

public:
	Joueur(string _nom);
	~Joueur();

	int get_coup();
	void set_coup(int _coup);

	string get_nom();
};

Joueur::Joueur(string _nom)
:m_coup(5),m_nom(_nom)
{}

Joueur::~Joueur()
{}

int Joueur::get_coup() {return m_coup;}
void Joueur::set_coup(int _coup) {m_coup = _coup;}
string Joueur::get_nom() {return m_nom;}



void init_plateau(map<string,Case>& Init)
{
	Init["A1"] = Case("A1",true);
	Init["A2"] = Case("A2",true);
	Init["A3"] = Case("A3",true);
	Init["A4"] = Case("A4",true);
	Init["A5"] = Case("A5",true);

	Init["B1"] = Case("B1",true);
	Init["B2"] = Case("B2",true);
	Init["B3"] = Case("B3",false);
	Init["B4"] = Case("B4",true);
	Init["B5"] = Case("B5",true);

	Init["C1"] = Case("C1",true);
	Init["C2"] = Case("C2",true);
	Init["C3"] = Case("C3",false);
	Init["C4"] = Case("C4",true);
	Init["C5"] = Case("C5",true);

	Init["D1"] = Case("D1",true);
	Init["D2"] = Case("D2",true);
	Init["D3"] = Case("D3",false);
	Init["D4"] = Case("D4",true);
	Init["D5"] = Case("D5",true);

	Init["E1"] = Case("E1",true);
	Init["E2"] = Case("E2",true);
	Init["E3"] = Case("E3",true);
	Init["E4"] = Case("E4",true);
	Init["E5"] = Case("E5",true);
}


void init_montagne(vector<Montagne>& elem)
{
	elem.push_back(Montagne("B3"));
	elem.push_back(Montagne("B4"));
	elem.push_back(Montagne("B5"));
}

bool test_elephant(vector<Pion>& pion, string a, Console* cons)
{	
	bool test = false;
	
	for(unsigned char v = 0; v < pion.size(); v++)
	{
		if(pion[v].get_coordonnees() == a)
		{
			if(pion[v].get_haut() == 1)
			{
				cons->setColor(COLOR_GREEN);
				cout << "E";
				cons->setColor(turquoise);
				cout << "h";

			}
			else if(pion[v].get_bas() == 1)
			{
				cons->setColor(COLOR_GREEN);
				cout << "E";
				cons->setColor(turquoise);
				cout << "b";

			}
			else if(pion[v].get_droite() == 1)
			{
				cons->setColor(COLOR_GREEN);
				cout << "E";
				cons->setColor(turquoise);
				cout << "d";

			}
			else if(pion[v].get_gauche() == 1)
			{
				cons->setColor(COLOR_GREEN);
				cout << "E";
				cons->setColor(turquoise);
				cout << "g";
			}
			test = true;
		}
	}
	cons->setColor(COLOR_DEFAULT);
	return test;
}

bool test_rhinoceros(vector<Pion>& pion, string a, Console* cons)
{	
	bool test = false;
	
	for(unsigned char v = 0; v < pion.size(); v++)
	{
		if(pion[v].get_coordonnees() == a)
		{
			if(pion[v].get_haut() == 1)
			{
				cons->setColor(COLOR_RED);
				cout << "R";
				cons->setColor(turquoise);
				cout << "h";
			}
			else if(pion[v].get_bas() == 1)
			{
				cons->setColor(COLOR_RED);
				cout << "R";
				cons->setColor(turquoise);
				cout << "b";
			}
			else if(pion[v].get_droite() == 1)
			{
				cons->setColor(COLOR_RED);
				cout << "R";
				cons->setColor(turquoise);
				cout << "d";
			}
			else if(pion[v].get_gauche() == 1)
			{
				cons->setColor(COLOR_RED);
				cout << "R";
				cons->setColor(turquoise);
				cout << "g";
			}
			test = true;
		}
	}
	cons->setColor(COLOR_DEFAULT);
	return test;
}


void affichage_plateau(map<string,Case>& Plateau, vector<Pion>& Elephant, vector<Pion>& Rhinoceros, vector<Montagne>& Montagne,Console* cons)
{
	string a;
	cout << endl << endl << endl << "\t";
	cons->setColor(COLOR_DEFAULT);
	for(int i = 1; i < 6; i++)
	{
		cout << "\t" << i;										    
	}
	cout << endl << endl;				
	for (char i = 'A'; i < 'F'; i++)
	{	
		cons->setColor(COLOR_DEFAULT);	
		cout << "\t" << i << "\t";
		for (char j = '1'; j < '6'; j++)
		{
			a = "";
			a += i;
			a += j;
			if(Plateau[a].get_libre() == true)
			{
				cons->setColor(COLOR_PURPLE);
				cout << "# ";
			}
			else
			{
				
				if(test_elephant(Elephant, a, cons) == true)
				{}
				else if(test_rhinoceros(Rhinoceros, a, cons) == true)
				{}
				else
				{
					cons->setColor(COLOR_YELLOW);
					cout << "M ";
				}
				
			}
			cout << "\t";
		}
		cout << endl << endl;
	}	
	cons->setColor(COLOR_DEFAULT);
}


void changer_orientation(vector<Pion>& Element)
{
	string coord_joueur;
	unsigned char ori;
	bool ok = false;
	do
	{
		cout << endl << "\t" << "Veuillez saisir la cordonnee du pion dont vous voulez modifier l'orientation" << endl;
		cin >> coord_joueur;
		for(int i = 0; i < Element.size(); i++)
		{
		    if(Element[i].get_coordonnees() == coord_joueur)
		    {
	do
	{
	    cout << endl << "\t" << "Veuillez saisir la nouvelle orientation du pion" << endl;
		cin >> ori;
	} while (ori != 'g' && ori != 'd' && ori != 'h' && ori != 'b');
	if(ori == 'g')
	{
	    Element[i].set_gauche(1);
	    Element[i].set_droite(0);
	    Element[i].set_haut(0);
	    Element[i].set_bas(0);
	}
	else if(ori == 'd')
	{
	   	Element[i].set_gauche(0);
	    Element[i].set_droite(1);
	    Element[i].set_haut(0);
	    Element[i].set_bas(0); 
	}
	else if(ori == 'h')
	{
	    Element[i].set_gauche(0);
	    Element[i].set_droite(0);
	    Element[i].set_haut(1);
	    Element[i].set_bas(0);
	}
	else if(ori == 'b')
	{
	    Element[i].set_gauche(0);
	    Element[i].set_droite(0);
	    Element[i].set_haut(0);
	    Element[i].set_bas(1);
	}
		        ok = true;
		    }
		}
	} while (ok == false);
}

void ajouter_pion(map<string,Case>& Plateau, vector<Pion>& Element, Joueur& player)
{	
	bool ok = false;
	string coord_joueur;
	unsigned char ori;
	int coup = 0;
	if(player.get_coup() != 0)
	{
		do
		{
			cout << endl << endl << "Veuillez saisir les coordonnees de votre nouveau pion : " << endl;
			cin >> coord_joueur;

			if (coord_joueur != "A1" && coord_joueur != "A2" && coord_joueur != "A3" && coord_joueur != "A4" && coord_joueur != "A5" && coord_joueur != "B1" && coord_joueur != "C1" && coord_joueur != "D1" && coord_joueur != "E1" && coord_joueur != "B5" && coord_joueur != "C5" && coord_joueur != "D5" && coord_joueur != "E2" && coord_joueur != "E3" && coord_joueur != "E4"&& coord_joueur != "E5")
			{
		        cout << "Veuillez placer votre pion sur l'une des cases exterieures du plateau";
		    }
		    else
		    {
		        if(Plateau[coord_joueur].get_libre() == true)
		        {
		            Plateau[coord_joueur].set_libre(false);
		            coup = player.get_coup();
		            coup -= 1;
		            player.set_coup(coup); // a adapter avec une methode joueur
		            ok = true;
		            do
		            {
		            	cout << endl << "Veuillez saisir l'orientation de votre nouveau pion : " << endl;
						cin >> ori;
		            }while(ori != 'g' && ori != 'd' && ori != 'h' && ori != 'b');
		            if(ori == 'g')
		            {
		           		Element.push_back(Pion(coord_joueur,0,0,1,0));	
		            }
		            if(ori == 'd')
		            {
		           		Element.push_back(Pion(coord_joueur,0,0,0,1));	
		            }
		            if(ori == 'h')
		            {
		           		Element.push_back(Pion(coord_joueur,1,0,0,0));	
		            }
		            if(ori == 'b')
		            {
		           		Element.push_back(Pion(coord_joueur,0,1,0,0));	
		            }

		        }
		        else // si la case est occupee a coder !! 
		        {
		            cout << "La case n'est pas libre.";
		        }
		    }

		}while(ok == false);	
	}
	else
	{
		cout << "Impossible, vous avez deja 5 pions sur le plateau";
	}
}

	


void deplacer_pion(map<string,Case>& Plateau, vector<Pion>& Element1, vector<Pion>& Element2, vector<Montagne>& Montagne, Joueur& J1, Joueur& J2)
{
	string coord_joueur = "";
	bool test = false;
	unsigned char orii;
	unsigned char ori = 0;
	int coup = 0;
	int vect = 0;
	float force = 0.1;
	string coord = "";
	bool boucle = true;
	do
	{
		cout << endl << endl << "\t" << "Veuillez saisir les coordonnees du pion a deplacer : " << endl;
		cin >> coord_joueur;
		for(int i = 0; i < Element1.size(); i++)
		{
		    if(Element1[i].get_coordonnees() == coord_joueur)
		    {
		        test = true;
		        vect = i;
		    }
		}

	}while(test == false);

	do
	{
	    cout << endl << "\t" << "Veuillez saisir la nouvelle orientation du pion" << endl;
		cin >> orii;
	} while (orii != 'g' && orii != 'd' && orii != 'h' && orii != 'b');
	if(orii == 'g')
	{
	    Element1[vect].set_gauche(1);
	    Element1[vect].set_droite(0);
	    Element1[vect].set_haut(0);
	    Element1[vect].set_bas(0);
	}
	else if(orii == 'd')
	{
	   	Element1[vect].set_gauche(0);
	    Element1[vect].set_droite(1);
	    Element1[vect].set_haut(0);
	    Element1[vect].set_bas(0); 
	}
	else if(orii == 'h')
	{
	    Element1[vect].set_gauche(0);
	    Element1[vect].set_droite(0);
	    Element1[vect].set_haut(1);
	    Element1[vect].set_bas(0);
	}
	else if(orii == 'b')
	{
	    Element1[vect].set_gauche(0);
	    Element1[vect].set_droite(0);
	    Element1[vect].set_haut(0);
	    Element1[vect].set_bas(1);
	}

	cout << endl << "\t" << "Veuillez saisir la direction dans laquelle vous voulez aller" << endl;
	cout << "\t" << "('g' pour gauche, 'd' pour droite, 'h' pour haut et 'b' pour bas) : " << endl;
	do
	{
		cin >> ori;
	}while(ori != 'g' && ori != 'd' && ori != 'h' && ori != 'b');

	cout << ori;

	if(ori == 'h')
	{
		if(coord_joueur[0] == 'A')
		{
		    Plateau[coord_joueur].set_libre(true);
		    J1.set_coup(J1.get_coup() + 1);
		    Element1[vect] = Element1[Element1.size() - 1];
		    Element1.pop_back();
		}
		else
		{
			force += Element1[vect].get_haut();
			
			do
			{
			    coord_joueur[0] -= 1;

			    if(Plateau[coord_joueur].get_libre() == true)
			    {
			    	Plateau[coord_joueur].set_libre(false);
			        boucle = false;
			    }
			    else
			    {
			    	for(int i = 0; i < Element1.size(); i++)
			    	{
			    	    if(Element1[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force += Element1[i].get_haut();
			    	        force -= Element1[i].get_bas();
			    	    }
			    	}
			    	for(int i = 0; i < Element2.size(); i++)
			    	{
			    	    if(Element2[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force += Element2[i].get_haut();
			    	        force -= Element2[i].get_bas();
			    	    }
			    	}
			    	for(int i = 0; i < Montagne.size(); i++)
			    	{
			    	    if(Montagne[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force += Montagne[i].get_haut();
			    	        force -= Montagne[i].get_bas();
			    	    }
			    	}
			    }
			} while (boucle == true && coord_joueur[0] != 'A');


			if(force > 0)
			{
				Plateau[Element1[vect].get_coordonnees()].set_libre(true);

				if(coord_joueur[0] == 'A')
				{	
				    for(int i = 0; i < Montagne.size(); i++)
			    	{
			    	    if(Montagne[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Montagne[i].get_coordonnees()[0] == 'A')
			    	    {
			    	        Montagne[i] = Montagne[Montagne.size() - 1];
			    	        Montagne.pop_back();
			    	    }
			    	}
			    	for(int i = 0; i < Element1.size(); i++)
			    	{
			    	    if(Element1[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Element1[i].get_coordonnees()[0] == 'A')
			    	    {
			    	    	coup = J1.get_coup();
			    	    	coup += 1;
			    	        J1.set_coup(coup);
			    	        Element1[i] = Element1[Element1.size() - 1];
			    	        Element1.pop_back();
			    	    }
			    	}
			    	for(int i = 0; i < Element2.size(); i++)
			    	{
			    	    if(Element2[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Element2[i].get_coordonnees()[0] == 'A')
			    	    {
			    	        coup = J2.get_coup();
			    	    	coup += 1;
			    	        J2.set_coup(coup);
			    	        Element2[i] = Element2[Element2.size() - 1];
			    	        Element2.pop_back();
			    	    }
			    	}
				}

				coord = "";
				coord[1] = coord_joueur[1];
				Plateau[coord_joueur].set_libre(false);
			   for(int i = 0; i < Montagne.size(); i++)
			    {
			        if(Montagne[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Montagne[i].get_coordonnees()[0] <= Element1[vect].get_coordonnees()[0] && Montagne[i].get_coordonnees()[0] >= coord_joueur[0])
			    	{
			    		coord = Montagne[i].get_coordonnees();
			    		coord[0] -= 1; 
			    		Montagne[i].set_coordonnees(coord);
			    	}
			    }
			    for(int i = 0; i < Element1.size(); i++)
			    {
			        if(Element1[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Element1[i].get_coordonnees()[0] <= Element1[vect].get_coordonnees()[0] && Element1[i].get_coordonnees()[0] >= coord_joueur[0])
			    	{
			    	    coord = Element1[i].get_coordonnees();
			    		coord[0] -= 1;
			    		Element1[i].set_coordonnees(coord);
			    	}
			    }
			    for(int i = 0; i < Element2.size(); i++)
			    {
			        if(Element2[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Element2[i].get_coordonnees()[0] <= Element1[vect].get_coordonnees()[0] && Element2[i].get_coordonnees()[0] >= coord_joueur[0])
			    	{
						coord = Element2[i].get_coordonnees();
			    		coord[0] -= 1; 
			    		Element2[i].set_coordonnees(coord);			    	
			    	}
			    }
			}
			else
			{
				cout << "Pas assez de force de poussee" << endl;
			}
		}
	}

	else if(ori == 'b')
	{
		if(coord_joueur[0] == 'E')
		{
		    Plateau[coord_joueur].set_libre(true);
		    J1.set_coup(J1.get_coup() + 1);
		    Element1[vect] = Element1[Element1.size() - 1];
		    Element1.pop_back();
		} 
		else
		{
			force += Element1[vect].get_bas();
			
			do
			{
			    coord_joueur[0] += 1;

			    if(Plateau[coord_joueur].get_libre() == true)
			    {
			    	Plateau[coord_joueur].set_libre(false);
			        boucle = false;
			    }
			    else
			    {
			    	for(int i = 0; i < Element1.size(); i++)
			    	{
			    	    if(Element1[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force -= Element1[i].get_haut();
			    	        force += Element1[i].get_bas();
			    	    }
			    	}
			    	for(int i = 0; i < Element2.size(); i++)
			    	{
			    	    if(Element2[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force -= Element2[i].get_haut();
			    	        force += Element2[i].get_bas();
			    	    }
			    	}
			    	for(int i = 0; i < Montagne.size(); i++)
			    	{
			    	    if(Montagne[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force -= Montagne[i].get_haut();
			    	        force += Montagne[i].get_bas();
			    	    }
			    	}
			    }
			} while (boucle == true && coord_joueur[0] != 'E');


			if(force > 0)
			{
				Plateau[Element1[vect].get_coordonnees()].set_libre(true);

				if(coord_joueur[0] == 'E')
				{	
				    for(int i = 0; i < Montagne.size(); i++)
			    	{
			    	    if(Montagne[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Montagne[i].get_coordonnees()[0] == 'E')
			    	    {
			    	        Montagne[i] = Montagne[Montagne.size() - 1];
			    	        Montagne.pop_back();
			    	    }
			    	}
			    	for(int i = 0; i < Element1.size(); i++)
			    	{
			    	    if(Element1[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Element1[i].get_coordonnees()[0] == 'E')
			    	    {
			    	        coup = J1.get_coup();
			    	    	coup += 1;
			    	        J1.set_coup(coup);
			    	        Element1[i] = Element1[Element1.size() - 1];
			    	        Element1.pop_back();
			    	    }
			    	}
			    	for(int i = 0; i < Element2.size(); i++)
			    	{
			    	    if(Element2[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Element2[i].get_coordonnees()[0] == 'E')
			    	    {
			    	        coup = J2.get_coup();
			    	    	coup += 1;
			    	        J2.set_coup(coup);
			    	        Element2[i] = Element2[Element2.size() - 1];
			    	        Element2.pop_back();
			    	    }
			    	}
				}

				coord = "";
				coord[1] = coord_joueur[1];
				Plateau[coord_joueur].set_libre(false);
			   for(int i = 0; i < Montagne.size(); i++)
			    {
			        if(Montagne[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Montagne[i].get_coordonnees()[0] >= Element1[vect].get_coordonnees()[0] && Montagne[i].get_coordonnees()[0] <= coord_joueur[0])
			    	{
			    		coord = Montagne[i].get_coordonnees();
			    		coord[0] += 1; 
			    		Montagne[i].set_coordonnees(coord);
			    	}
			    }
			    for(int i = 0; i < Element1.size(); i++)
			    {
			        if(Element1[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Element1[i].get_coordonnees()[0] >= Element1[vect].get_coordonnees()[0] && Element1[i].get_coordonnees()[0] <= coord_joueur[0])
			    	{
			    	    coord = Element1[i].get_coordonnees();
			    		coord[0] += 1;
			    		Element1[i].set_coordonnees(coord);
			    	}
			    }
			    for(int i = 0; i < Element2.size(); i++)
			    {
			        if(Element2[i].get_coordonnees()[1] == Element1[vect].get_coordonnees()[1] && Element2[i].get_coordonnees()[0] >= Element1[vect].get_coordonnees()[0] && Element2[i].get_coordonnees()[0] <= coord_joueur[0])
			    	{
						coord = Element2[i].get_coordonnees();
			    		coord[0] += 1; 
			    		Element2[i].set_coordonnees(coord);			    	
			    	}
			    }
			}
			else
			{
				cout << "Pas assez de force de poussee" << endl;
			}
		}
	}
	
	else if(ori == 'g')
	{
		if(coord_joueur[1] == '1')
		{
		    Plateau[coord_joueur].set_libre(true);
		    J1.set_coup(J1.get_coup() + 1);
		    Element1[vect] = Element1[Element1.size() - 1];
		    Element1.pop_back();
		}  
		else
		{
			force += Element1[vect].get_gauche();
			
			do
			{
			    coord_joueur[1] -= 1;

			    if(Plateau[coord_joueur].get_libre() == true)
			    {
			    	Plateau[coord_joueur].set_libre(false);
			        boucle = false;
			    }
			    else
			    {
			    	for(int i = 0; i < Element1.size(); i++)
			    	{
			    	    if(Element1[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force -= Element1[i].get_droite();
			    	        force += Element1[i].get_gauche();
			    	    }
			    	}
			    	for(int i = 0; i < Element2.size(); i++)
			    	{
			    	    if(Element2[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force -= Element2[i].get_droite();
			    	        force += Element2[i].get_gauche();
			    	    }
			    	}
			    	for(int i = 0; i < Montagne.size(); i++)
			    	{
			    	    if(Montagne[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force -= Montagne[i].get_droite();
			    	        force += Montagne[i].get_gauche();
			    	    }
			    	}
			    }
			} while (boucle == true && coord_joueur[1] != '1');


			if(force > 0)
			{
				Plateau[Element1[vect].get_coordonnees()].set_libre(true);

				if(coord_joueur[1] == '1')
				{	
				    for(int i = 0; i < Montagne.size(); i++)
			    	{
			    	    if(Montagne[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Montagne[i].get_coordonnees()[1] == '1')
			    	    {
			    	        Montagne[i] = Montagne[Montagne.size() - 1];
			    	        Montagne.pop_back();
			    	    }
			    	}
			    	for(int i = 0; i < Element1.size(); i++)
			    	{
			    	    if(Element1[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Element1[i].get_coordonnees()[1] == '1')
			    	    {
			    	        coup = J1.get_coup();
			    	    	coup += 1;
			    	        J1.set_coup(coup);
			    	        Element1[i] = Element1[Element1.size() - 1];
			    	        Element1.pop_back();
			    	    }
			    	}
			    	for(int i = 0; i < Element2.size(); i++)
			    	{
			    	    if(Element2[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Element2[i].get_coordonnees()[1] == '1')
			    	    {
			    	        coup = J2.get_coup();
			    	    	coup += 1;
			    	        J2.set_coup(coup);
			    	        Element2[i] = Element2[Element2.size() - 1];
			    	        Element2.pop_back();
			    	    }
			    	}
				}

				coord = "00";
				coord[0] = coord_joueur[0];
				Plateau[coord_joueur].set_libre(false);
			   for(int i = 0; i < Montagne.size(); i++)
			    {
			        if(Montagne[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Montagne[i].get_coordonnees()[1] <= Element1[vect].get_coordonnees()[1] && Montagne[i].get_coordonnees()[1] >= coord_joueur[1])
			    	{
			    		coord = Montagne[i].get_coordonnees();
			    		coord[1] -= 1; 
			    		Montagne[i].set_coordonnees(coord);
			    	}
			    }
			    for(int i = 0; i < Element1.size(); i++)
			    {
			        if(Element1[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Element1[i].get_coordonnees()[1] <= Element1[vect].get_coordonnees()[1] && Element1[i].get_coordonnees()[1] >= coord_joueur[1])
			    	{
			    	    coord = Element1[i].get_coordonnees();
			    		coord[1] -= 1;
			    		Element1[i].set_coordonnees(coord);
			    	}
			    }
			    for(int i = 0; i < Element2.size(); i++)
			    {
			        if(Element2[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Element2[i].get_coordonnees()[1] <= Element1[vect].get_coordonnees()[1] && Element2[i].get_coordonnees()[1] >= coord_joueur[1])
			    	{
						coord = Element2[i].get_coordonnees();
			    		coord[1] -= 1; 
			    		Element2[i].set_coordonnees(coord);			    	
			    	}
			    }
			}
			else
			{
				cout << "Pas assez de force de poussee" << endl;
			}
		}
	}

	else if(ori == 'd')
	{
		if(coord_joueur[1] == '5')
		{
		    Plateau[coord_joueur].set_libre(true);
		    J1.set_coup(J1.get_coup() + 1);
		    Element1[vect] = Element1[Element1.size() - 1];
		    Element1.pop_back();
		}  
		else
		{
			force += Element1[vect].get_droite();
			
			do
			{
			    coord_joueur[1] += 1;

			    if(Plateau[coord_joueur].get_libre() == true)
			    {
			    	Plateau[coord_joueur].set_libre(false);
			        boucle = false;
			    }
			    else
			    {
			    	for(int i = 0; i < Element1.size(); i++)
			    	{
			    	    if(Element1[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force += Element1[i].get_droite();
			    	        force -= Element1[i].get_gauche();
			    	    }
			    	}
			    	for(int i = 0; i < Element2.size(); i++)
			    	{
			    	    if(Element2[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force += Element2[i].get_droite();
			    	        force -= Element2[i].get_gauche();
			    	    }
			    	}
			    	for(int i = 0; i < Montagne.size(); i++)
			    	{
			    	    if(Montagne[i].get_coordonnees() == coord_joueur)
			    	    {
			    	        force += Montagne[i].get_droite();
			    	        force -= Montagne[i].get_gauche();
			    	    }
			    	}
			    }
			} while (boucle == true && coord_joueur[1] != '5');


			if(force > 0)
			{
				Plateau[Element1[vect].get_coordonnees()].set_libre(true);

				if(coord_joueur[1] == '5')
				{	
				    for(int i = 0; i < Montagne.size(); i++)
			    	{
			    	    if(Montagne[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Montagne[i].get_coordonnees()[1] == '5')
			    	    {
			    	        Montagne[i] = Montagne[Montagne.size() - 1];
			    	        Montagne.pop_back();
			    	    }
			    	}
			    	for(int i = 0; i < Element1.size(); i++)
			    	{
			    	    if(Element1[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Element1[i].get_coordonnees()[1] == '5')
			    	    {
			    	        coup = J1.get_coup();
			    	    	coup += 1;
			    	        J1.set_coup(coup);
			    	        Element1[i] = Element1[Element1.size() - 1];
			    	        Element1.pop_back();
			    	    }
			    	}
			    	for(int i = 0; i < Element2.size(); i++)
			    	{
			    	    if(Element2[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Element2[i].get_coordonnees()[1] == '5')
			    	    {
			    	        coup = J2.get_coup();
			    	    	coup += 1;
			    	        J2.set_coup(coup);
			    	        Element2[i] = Element2[Element2.size() - 1];
			    	        Element2.pop_back();
			    	    }
			    	}
				}

				coord = "00";
				coord[0] = coord_joueur[0];
				Plateau[coord_joueur].set_libre(false);
			   for(int i = 0; i < Montagne.size(); i++)
			    {
			        if(Montagne[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Montagne[i].get_coordonnees()[1] >= Element1[vect].get_coordonnees()[1] && Montagne[i].get_coordonnees()[1] <= coord_joueur[1])
			    	{
			    		coord = Montagne[i].get_coordonnees();
			    		coord[1] += 1; 
			    		Montagne[i].set_coordonnees(coord);
			    	}
			    }
			    for(int i = 0; i < Element1.size(); i++)
			    {
			        if(Element1[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Element1[i].get_coordonnees()[1] >= Element1[vect].get_coordonnees()[1] && Element1[i].get_coordonnees()[1] <= coord_joueur[1])
			    	{
			    	    coord = Element1[i].get_coordonnees();
			    		coord[1] += 1;
			    		Element1[i].set_coordonnees(coord);
			    	}
			    }
			    for(int i = 0; i < Element2.size(); i++)
			    {
			        if(Element2[i].get_coordonnees()[0] == Element1[vect].get_coordonnees()[0] && Element2[i].get_coordonnees()[1] >= Element1[vect].get_coordonnees()[1] && Element2[i].get_coordonnees()[1] <= coord_joueur[1])
			    	{
						coord = Element2[i].get_coordonnees();
			    		coord[1] += 1; 
			    		Element2[i].set_coordonnees(coord);			    	
			    	}
			    }
			}
			else
			{
				cout << "Pas assez de force de poussee" << endl;
			}
		}
	}

}


void jouer(map<string,Case>& Plateau, vector<Pion>& Element, vector<Pion>& Element2, vector<Montagne>& Montagne, Joueur& player1, Joueur& player2)
{
	int choix = 0;
	cout << endl << "\t" << "Au tour de " << player1.get_nom() << " de jouer" << endl << endl;
	cout << "\t" << "1. Ajouter pion" << endl;
	cout << "\t" << "2. Changer l'orientation d'un pion" << endl;
	cout << "\t" << "3. Deplacer un pion" << endl;
	do
	{
	choix = 0;
	cin >> choix;
	if((choix == 2 && player1.get_coup() == 5) || (choix == 3 && player1.get_coup() == 5))
	{
	    cout << "Vous n'avez aucun pion sur le plateau, revoyez votre choix" << endl << endl;
	    choix = 0;
	}
	} while (choix != 1 && choix != 2 && choix != 3);

	if(choix == 1)
	{
	    ajouter_pion(Plateau, Element, player1);
	}
	else if(choix == 2)
	{
		changer_orientation(Element); 
	}
	else if(choix == 3)
	{
		deplacer_pion(Plateau, Element, Element2, Montagne, player1, player2);
	}
	system("pause");

}

void Siam(Console* cons)
{
	string p1, p2;
	int win = 0;

	cout << "Entrez le nom du joueur 1" << endl;
	cin >> p1;

	system("cls");

	cout << "Entrez le nom du joueur 2" << endl;
	cin >> p2;

	system("cls");

	map<string,Case> Plateau;			// Declaration des conteneurs
	vector<Pion> Elephant;
	vector<Pion> Rhinoceros;
	vector<Montagne> Montagne;
	Joueur Player_1(p1), Player_2(p2);

	cout << endl << Player_1.get_nom() << " joue les Elephants" << endl;
	cout << endl << Player_2.get_nom() << " joue les Rhinoceros" << endl << endl;

	system("pause");
	system("cls");
	

	init_plateau(Plateau);				// Initialisation des conteneurs
	init_montagne(Montagne);


	do
	{
		affichage_plateau(Plateau,Elephant,Rhinoceros,Montagne,cons);
		jouer(Plateau,Elephant, Rhinoceros, Montagne, Player_1, Player_2);
		system("cls");

		if(Montagne.size() == 2)
		{
			win = 1;
		}

		if(win == 0)
		{
		affichage_plateau(Plateau,Elephant,Rhinoceros,Montagne,cons);
		jouer(Plateau,Rhinoceros, Elephant, Montagne, Player_2, Player_1);
		system("cls");
		}

		if(Montagne.size() == 2 && win == 0)
		{
			win = 2;
		}

	}while(win != 1 && win != 2);

	if(win == 1)
	{
	    cout << "Bravo, " << Player_1.get_nom() << " a gagne" << endl;
	}
	else
	{
		cout << "Bravo, " << Player_2.get_nom() << " a gagne" << endl;
	}
	
	system("pause");
}

void regle()

{
	int boucle = 0;

	do
	{
		system("cls");
		cout << endl << endl << "\t" << " Chaque joueur choisit son animal. Les joueurs joueront a tour de role. \n " << endl;
		cout << "\t"  << "Au debut du jeu les animaux sont disposes a l'exterieur du plateau et les montagnes au centre du plateau. \n" << endl;
		cout << "\t"  << "Chaque case du plateau est reperee par ses coordonnees : ligne A a E, colonne 1 a 5. \n" << endl;
		cout << "\t"  << " Les elephants blancs, animaux sacres dans le royaume de SIAM commenceront a jouer.\n "<< endl ;
		cout << "\t"  << "Les joueurs ne pourront jouer a chaque tour de jeu qu'un seul de leur animal et ne faire qu'une des 5 actions suivantes :\n " << endl ;
		cout << "\t"  << "- Entrer un de ses animaux sur le plateau \n" << endl ;
		cout << "\t"  << "- Se deplacer sur une case libre  Changer l'orientation de son animal sans changer de case \n" << endl;
		cout << "\t"  << "- Changer l'orientation de son animal sans changer de case \n" << endl;
		cout << "\t"  << "- Sortir un de ses animaux disposes sur une case exterieure (case avec un +)\n" << endl;
		cout << "\t"  << "- Se deplacer en poussant d'autres pieces disposees sur le plateau \n" << endl ;
		cout << "\t"  << "- Entrer un de ses animaux sur le plateau \n" << endl;
		cout << "\t"  << "Vous devez entrer un de vos animaux par l'une des cases exterieures a condition qu'elle soit libre \n" << endl ;
		cout << "\t"  << " Pour placer l’animal dans une case, vous saisirez au clavier ses coordonnees correctes.  Pour orienter l’animal, il faut saisir l’une des 4 directions choisies." << endl;
		cout << "\t"  << "La validation se fera avec la touche Entree" << endl << endl << endl;
		cout << "\t"  << "Entrez 1 pour retourner au menu" << endl;
		cin >> boucle;
	}while(boucle != 0);
}

int main()
{
	Console* cons;
	cons =  Console::getInstance();
	cons->setColor(COLOR_GREEN);
	string choix = "0";
	do
	{
		system("cls");
		cout << endl << "\t\t\t" << "***Menu***" << endl << endl;
		cout << "\t\t"  << "1. Jouer" << endl;
		cout << "\t\t"  << "2. Lire les regles" << endl;
		cout << "\t\t"  << "3. Quitter" << endl << endl;
		do{
			cin.clear();
		    cin >> choix;
		} while (choix != "1" && choix != "2" && choix != "3");
		
		
		if(choix == "1")
		{
		    system("cls");
		    Siam(cons);
		}
		else if(choix == "2")
		{
		    system("cls");
		    regle();
		}
		

	}while(choix != "3");

    return 0;
}