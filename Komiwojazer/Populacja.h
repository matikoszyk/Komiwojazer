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
	// wektor odleg³osci
	std::vector<int> dystans; 
public:
	// Konstruktor, który tworzy populacjê na podstawie podanego rozmiaru
	Populacja(int rozmiar, Trasa& trasa, Miasta& miasta); 	
	// Destruktor
	~Populacja();
	// Metoda wyœwietlaj¹ca populacjê
	void wyswietl_populacje();			 
	// Metoda wyœwietlaj¹ca najkrótsz¹ trasê w populacji
	void wyswietl_najkrotsza();		
	//Metoda zwracaj¹ca najkrótsz¹ trasê
	int get_najkrotsza();
	// Metoda selekcji, wybieranie metod¹ ruletki
	void Selekcja();	
	// Metoda wykonuj¹ca Krzy¿owaniePMX
	void KrzyzowaniePMX(Miasta& miasta);  
	// Metoda mutacji
	void Mutacja(Miasta& miasta, float prawdopodobienstwo); 
};


