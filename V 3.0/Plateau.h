#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include "Perso.h"

void afficher_details_map(map<int,Perso> plateau);  // Prototype de la procédure qui affiche tous les détails d'une case

void afficher_map(map<int,Perso> plateau);  // Prototype de la procédure qui affiche le plateau

map<int,Perso> init();  // Prototype de la fonction qui initialise le tableau


#endif