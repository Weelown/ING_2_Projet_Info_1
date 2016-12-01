#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED


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

using namespace std;

void init_plateau(map<string,Case>& Init);
void init_montagne(vector<Montagne>& elem);
bool test_elephant(vector<Pion>& pion, string a, Console* cons);
bool test_rhinoceros(vector<Pion>& pion, string a, Console* cons);
void affichage_plateau(map<string,Case>& Plateau, vector<Pion>& Elephant, vector<Pion>& Rhinoceros, vector<Montagne>& Montagne,Console* cons);
void changer_orientation(vector<Pion>& Element);
void ajouter_pion(map<string,Case>& Plateau, vector<Pion>& Element, Joueur& player);
void deplacer_pion(map<string,Case>& Plateau, vector<Pion>& Element1, vector<Pion>& Element2, vector<Montagne>& Montagne, Joueur& J1, Joueur& J2);
void jouer(map<string,Case>& Plateau, vector<Pion>& Element, vector<Pion>& Element2, vector<Montagne>& Montagne, Joueur& player1, Joueur& player2);
void Siam(Console* cons);
void ordinateur(Console* cons);
void regle();

#endif // UTILS_H_INCLUDED
