/*
* @Author: Romain_Gérardin
* @Date:   2016-11-04 20:11:20
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-11-04 22:15:57
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include "Perso.h"

using namespace std;

// Définition des constructeurs

	Perso::Perso()
	:m_perso('#'), m_nom("Initialisation"), m_orientation(0), m_gauche(0), m_droite(0), m_haut(0), m_bas(0)
	{}

	Perso::Perso(Perso const& copy)
	:m_perso(copy.m_perso), m_nom(copy.m_nom), m_orientation(copy.m_orientation), m_haut(copy.m_haut), m_bas(copy.m_bas), m_gauche(copy.m_gauche), m_droite(copy.m_droite)
	{}

	Perso::Perso(char _perso, string _nom, char _orientation, float _haut, float _bas, float _gauche, float _droite)
	:m_perso(_perso), m_nom(_nom), m_orientation(_orientation), m_haut(_haut), m_bas(_bas), m_droite(_droite), m_gauche(_gauche)
	{}


 // Définition des getters

	char Perso::get_perso() {return m_perso;}
	string Perso::get_nom() {return m_nom;}
	char Perso::get_orientation() {return m_orientation;}
	float Perso::get_haut() {return m_haut;}
	float Perso::get_bas() {return m_bas;}
	float Perso::get_gauche() {return m_gauche;}
	float Perso::get_droite() {return m_droite;}


// Définition des setters

	void Perso::set_perso(char _perso) {m_perso = _perso;}
	void Perso::set_nom(string _nom) {m_nom = _nom;}
	void Perso::set_orientation(char _orientation) {m_orientation = _orientation;}
	void Perso::set_haut(float _haut) {m_haut = _haut;}
	void Perso::set_bas(float _bas) {m_bas = _bas;}
	void Perso::set_gauche(float _gauche) {m_gauche = _gauche;}
	void Perso::set_droite(float _droite) {m_droite = _droite;}


// Définition des autres fonctions relative à la classe Perso :

	void Perso::affichage_details_perso()
	{
			cout << "\t" << get_perso() << endl << "\t" << get_nom() << endl << "\t" << get_gauche() << endl << "\t" << get_droite() << endl << "\t" << get_haut() << endl << "\t" << get_bas() << endl << endl;

	}