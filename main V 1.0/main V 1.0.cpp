/*
* @Author: Romain_Gérardin
* @Date:   2016-11-01 19:03:06
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-03 09:15:28
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Perso
{
private:
	int m_perso;
	string m_nom;
	char m_orientation;

public:
	Perso();
	Perso(Perso const& cop);
	Perso(int _perso, string _nom, char _orientation);

	int get_perso();
	string get_nom();
	char get_orientation();

	void set_perso(int _perso);
	void set_nom(string _nom);
	void set_orientation(char _orientation);
};

	Perso::Perso()
	:m_perso('#'), m_nom("Initialisation"), m_orientation(0)
	{}

	Perso::Perso(Perso const& copy)
	:m_perso(copy.m_perso), m_nom(copy.m_nom), m_orientation(copy.m_orientation)
	{}

	Perso::Perso(int _perso, string _nom, char _orientation)
	:m_perso(_perso), m_nom(_nom), m_orientation(_orientation)
	{}

	int Perso::get_perso() {return m_perso;}
	string Perso::get_nom() {return m_nom;}
	char Perso::get_orientation() {return m_orientation;}

	void Perso::set_perso(int _perso)
	{
		m_perso = _perso;
	}

	void Perso::set_nom(string _nom)
	{
		m_nom = _nom;
	}

	void Perso::set_orientation(char _orientation)
	{
		m_orientation = _orientation;
	}
// 00 01 02 03 04
// 10 11 12 13 14
// 20 21 22 23 24
// 30 31 32 33 34
// 40 41 42 43 44

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



int main()
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
	}

	afficher_map(plateau);

	system("pause");


    return 0;
}