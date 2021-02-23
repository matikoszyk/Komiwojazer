#pragma once
#include "Miasta.h"
#include "Trasa.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


class Populacja
{
private:
	// wektor populacji
	std::vector<Trasa> popul;  
	// wektor odleg�osci
	std::vector<int> dystans; 
public:
	// Konstruktor, kt�ry tworzy populacj� na podstawie podanego rozmiaru
	Populacja(int rozmiar, Trasa& trasa, Miasta& miasta); 	
	// Destruktor
	~Populacja();
	// Metoda wy�wietlaj�ca populacj�
	void wyswietl_populacje();			 
	// Metoda wy�wietlaj�ca najkr�tsz� tras� w populacji
	void wyswietl_najkrotsza();		
	//Metoda zwracaj�ca najkr�tsz� tras�
	int get_najkrotsza();
	// Metoda selekcji, wybieranie metod� ruletki
	void Selekcja();	
	// Metoda wykonuj�ca Krzy�owaniePMX
	void KrzyzowaniePMX(Miasta& miasta);  
	// Metoda mutacji
	void Mutacja(Miasta& miasta, float prawdopodobienstwo); 
};


