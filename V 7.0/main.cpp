/*
* @Author: Romain_Gérardin
* @Date:   2016-11-15 20:36:19
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-28 09:53:29
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



class Pion :public Piece 																	// Class Pion (Elephant / Rhinocéros)
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

bool test_elephant(vector<Pion>& pion, string a)
{	
	bool test = false;
	
	for(unsigned char v = 0; v < pion.size(); v++)
	{
		if(pion[v].get_coordonnees() == a)
		{
			if(pion[v].get_haut() == 1)
			{
				cout << "Eh";
			}
			else if(pion[v].get_bas() == 1)
			{
				cout << "Eb";
			}
			else if(pion[v].get_droite() == 1)
			{
				cout << "Ed";
			}
			else if(pion[v].get_gauche() == 1)
			{
				cout << "Eg";
			}
			test = true;
		}
	}

	return test;
}

bool test_rhinoceros(vector<Pion>& pion, string a)
{	
	bool test = false;
	
	for(unsigned char v = 0; v < pion.size(); v++)
	{
		if(pion[v].get_coordonnees() == a)
		{
			if(pion[v].get_haut() == 1)
			{
				cout << "Rh";
			}
			else if(pion[v].get_bas() == 1)
			{
				cout << "Rb";
			}
			else if(pion[v].get_droite() == 1)
			{
				cout << "Rd";
			}
			else if(pion[v].get_gauche() == 1)
			{
				cout << "Rg";
			}
			test = true;
		}
	}

	return test;
}


void affichage_plateau(map<string,Case>& Plateau, vector<Pion>& Elephant, vector<Pion>& Rhinoceros, vector<Montagne>& Montagne)
{
	string a;
	cout << endl << endl << endl;											
	for (char i = 'A'; i < 'F'; i++)
	{		
		for (char j = '1'; j < '6'; j++)
		{
			a = "";
			a += i;
			a += j;
			if(Plateau[a].get_libre() == true)
			{
				cout << "# ";
			}
			else
			{
				
				if(test_elephant(Elephant, a) == true)
				{}
				else if(test_rhinoceros(Rhinoceros, a) == true)
				{}
				else
				{
					cout << "M ";
				}
				
			}
			
			cout << "\t\t";
		}
		cout << endl << endl;
	}	
}


void changer_orientation(vector<Pion>& Element)
{
	string coord_joueur;
	unsigned char ori;
	bool ok = false;
	do
	{
		cout << endl << "Veuillez saisir la cordonnee du pion dont vous voulez modifier l'orientation";
		cin >> coord_joueur;
		for(int i = 0; i < Element.size(); i++)
		{
		    if(Element[i].get_coordonnees() == coord_joueur)
		    {
		    	do
	{
	    cout << endl << "Veuillez saisir la nouvelle orientation du pion";
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

void ajouter_pion(map<string,Case>& Plateau, vector<Pion>& Element, Joueur player)
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
		            player.set_coup(coup); // à adapter avec une méthode joueur
		            ok = true;
		            do
		            {
		            	cout << endl << "Veuillez saisir l'orientation de votre nouveau pion : ";
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
		        else // si la case est occupée à coder !! 
		        {
		            if(coord_joueur[1] == 1)
		            {
		                
		            }
		        }
		    }	
		}while(ok == false);	
	}
	else
	{
		cout << "Impossible, vous avez déjà 5 pions sur le plateau";
	}
	
}

void deplacer_pion(map<string,Case>& Plateau, vector<Pion>& Elephant, vector<Pion>& Rhinoceros, vector<Montagne>& Montagne)
{

}


void jouer(map<string,Case>& Plateau, vector<Pion>& Element, Joueur player)
{
	int choix = 0;
	cout << "Au tour de " << player.get_nom() << " de jouer" << endl << endl;
	cout << "1. Ajouter pion" << endl;
	cout << "2. Changer l'orientation d'un pion" << endl;
	cout << "3. Deplacer un pion" << endl;
	do
	{
	cin >> choix;
	if(choix == 2 && player.get_coup() == 5)
	{
	    cout << "Vous n'avez aucun pion sur le plateau, revoyez votre choix" << endl << endl;
	    choix = 0;
	}
	} while (choix != 1 && choix != 2 && choix != 3);

	if(choix == 1)
	{
	    ajouter_pion(Plateau, Element, player);
	}
	else if(choix == 2)
	{
		changer_orientation(Element); 
	}
	else
	{
		// deplacer_pion();
	}
	cout << (int)player.get_coup();
	system("pause");

}

void Siam()
{
	string p1, p2;
	unsigned char win = 0;

	cout << "Entrez le nom du joueur 1" << endl;
	cin >> p1;

	system("cls");

	cout << "Entrez le nom du joueur 2" << endl;
	cin >> p2;

	system("cls");

	Joueur Player_1(p1), Player_2(p2);

	cout << endl << Player_1.get_nom() << " joue les Elephants" << endl;
	cout << endl << Player_2.get_nom() << " joue les Rhinoceros" << endl << endl;

	system("pause");
	system("cls");
	
	map<string,Case> Plateau;			// Déclaration des conteneurs
	vector<Pion> Elephant;
	vector<Pion> Rhinoceros;
	vector<Montagne> Montagne;

	init_plateau(Plateau);				// Initialisation des conteneurs
	init_montagne(Montagne);


	do
	{
	affichage_plateau(Plateau,Elephant,Rhinoceros,Montagne);
	jouer(Plateau, Elephant, Player_1);
	system("cls");
	if(Montagne.size() == 2)
	{
		win = 1;
	}
	if(win == 0)
	{
		affichage_plateau(Plateau,Elephant,Rhinoceros,Montagne);
		jouer(Plateau, Rhinoceros, Player_2);
		system("cls");
	}
	if(Montagne.size() == 2 && win == 0)
	{
		win = 2;
	}
	}while(win != 1 && win != 2);

	if(win == 1)
	{
	    cout << "Bravo, " << Player_1.get_nom() << " a gagne";
	}
	else
	{
		cout << "Bravo, " << Player_2.get_nom() << " a gagne";
	}
	
	system("pause");
}

void regle()
{}

int main()
{
	int choix = 0;
	do
	{
	system("cls");
	cout << "***Menu***" << endl << endl;
	cout << "1. Jouer" << endl;
	cout << "2. Lire les regles" << endl;
	cout << "3. Quitter" << endl << endl;
	cin >> choix;
	if(choix == 1)
	{	
		system("cls");
		Siam();
	}
	if(choix == 2)
	{
		system("cls");
	    regle();
	}
	}while(choix != 3);

    return 0;
}