/*
* @Author: Romain_Gérardin
* @Date:   2016-11-04 20:39:02
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-04 22:13:05
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include "Perso.h"
#include "Plateau.h"

using namespace std;


void afficher_details_map(map<int,Perso> plateau)  // Procédure qui affiche tous les détails d'une case
{
	for(int j = 0; j < 50; j = j + 10)
	{
		for(int i = 1; i < 6; i++)
		{
			plateau[i + j].affichage_details_perso();
		}
	}
}


void afficher_map(map<int,Perso> plateau)  // Procédure qui affiche le plateau
{

	for(int j = 0; j < 50; j = j + 10)
	{
		cout << endl << "\t";
		for(int i = 1; i < 6; i++)
		{
			cout << plateau[i + j].get_perso() << "\t";
		}
		cout << endl;
	}
}


map<int,Perso> init()  // Fonction qui initialise le plateau
{
	map<int,Perso> plateau;

	for(int j = 0; j < 50; j = j + 10)
	{
		for(int i = 1; i < 6; i++)
		{
			plateau[i + j] = Perso();
		}
	}
	plateau[13] = Perso('M',"Montagne",0,0.9,0.9,0.9,0.9);
	plateau[23] = Perso('M',"Montagne",0,0.9,0.9,0.9,0.9);
	plateau[33] = Perso('M',"Montagne",0,0.9,0.9,0.9,0.9);

	return plateau;
}
