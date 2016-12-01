/*
* @Author: Romain_Gerardin
* @Date:   2016-11-15 20:36:19
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-30 19:34:59
*/

#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "console.h"
#include "joueur.h"
#include "cordonnees.h"
#include "case.h"
#include "piece.h"
#include "pion.h"
#include "utils.h"

using namespace std;

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
		cout << "\t\t"  << "1. Jouer contre un joueur" << endl;
		cout << "\t\t"  << "2. Jouer contre l'IA" << endl;
		cout << "\t\t"  << "3. Lire les regles" << endl;
		cout << "\t\t"  << "4. Quitter" << endl << endl;
		do{
			cin.clear();
		    cin >> choix;
		} while (choix != "1" && choix != "2" && choix != "3" && choix != "4");


		if(choix == "1")
		{
		    system("cls");
		    Siam(cons);
		}
		else if(choix == "2")
		{
		    system("cls");
		    ordinateur(cons);
		}
		else if(choix == "3")
		{
		    system("cls");
		    regle();
		}


	}while(choix != "3");


    return 0;
}
