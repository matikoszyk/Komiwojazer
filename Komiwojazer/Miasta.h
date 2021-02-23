#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Miasta
{
private:
	// Liczba miast. Pobiera liczbê miast z pliku tekstowego
	int liczba_miast; 
	// Odleg³oœci miedzy miastami zapisane w tablicy
	std::vector<std::vector<int>> tablica;  


public:

	// Konstruktor macierzy odleg³oœci odczytywanych z pliku tekstowego
	Miasta(const std::string& nazwa_pliku); 
	// destruktor
	~Miasta(); 
	//Metoda, która zwraca liczbê miast
	int getLiczbaMiast(); 
	// Metoda, która zwraca dystans z miasta do miasta
	int getDystans(int i, int j);  

};
