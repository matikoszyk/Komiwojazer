#pragma once
#include "Miasta.h"
#include <algorithm>
#include <iostream>
#include <vector>

class Trasa
{
private:
	// Pojedyncza trasa w wektorze
	std::vector<int> jedna_trasa;  
	friend class Populacja;  
public:
	// Konstruktor Domyœlny
	Trasa();  
	// Konstruktor na podstawie iloœci miast
	Trasa(int rozmiar); 
	// Destru
	~Trasa(); 
	// Metoda mieszaj¹ca trasê
	void losowa_trasa(); 
	// Metoda wyznaczaj¹ca d³ugoœæ danej trasy
	int dystans(Miasta& miasta); 
	// Metoda wyœwietlaj¹ca trasê
	void wyswietl_trase(); 
	// Metoda, która zwraca rozmiar wektora trasy
	int rozmiar_trasy(); 
	// Metoda, która zwraca numer miasta o konkretnym indeksie.
	int getNumerMiasta(int index); 
};