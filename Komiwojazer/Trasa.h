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
	// Konstruktor Domy�lny
	Trasa();  
	// Konstruktor na podstawie ilo�ci miast
	Trasa(int rozmiar); 
	// Destru
	~Trasa(); 
	// Metoda mieszaj�ca tras�
	void losowa_trasa(); 
	// Metoda wyznaczaj�ca d�ugo�� danej trasy
	int dystans(Miasta& miasta); 
	// Metoda wy�wietlaj�ca tras�
	void wyswietl_trase(); 
	// Metoda, kt�ra zwraca rozmiar wektora trasy
	int rozmiar_trasy(); 
	// Metoda, kt�ra zwraca numer miasta o konkretnym indeksie.
	int getNumerMiasta(int index); 
};