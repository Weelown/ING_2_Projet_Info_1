/*
* @Author: Romain_Gérardin
* @Date:   2016-11-01 19:03:06
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-04 22:18:44
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include "Perso.h"
#include "Plateau.h"

using namespace std;



																			// Plateau :

																			// A1 A2 A3 A4 A5			1  2  3  4  5
																			// B1 B2 B3 B4 B5			11 12 13 14 15
																			// C1 C2 C3 C4 C5			21 22 23 24 25
																			// D1 D2 D3 D4 D5			31 32 33 34 35
																			// E1 E2 E3 E4 E5			41 42 43 44 45



int main()
{	

	map<int,Perso> plateau;  // Déclaration de la map

	int choix(0);

	plateau = init();  // Initialisation de la map
	
	afficher_details_map(plateau);  // Affichage de tous les éléments de chaque case

	cout << endl;

	system("pause");
	system("cls");

	afficher_map(plateau);  // Affichage du pateau

	cout << endl;

	system("pause");
	system("cls");

	do 													// Test affichage case selectionnée
	{

		cin >> choix;

		cout << endl;

		plateau[choix].affichage_details_perso();

		cout << endl;

		system("pause");

		system("cls");

	}while(choix != -1);


    return 0;
}