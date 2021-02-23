#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Miasta
{
private:
	// Liczba miast. Pobiera liczb� miast z pliku tekstowego
	int liczba_miast; 
	// Odleg�o�ci miedzy miastami zapisane w tablicy
	std::vector<std::vector<int>> tablica;  


public:

	// Konstruktor macierzy odleg�o�ci odczytywanych z pliku tekstowego
	Miasta(const std::string& nazwa_pliku); 
	// destruktor
	~Miasta(); 
	//Metoda, kt�ra zwraca liczb� miast
	int getLiczbaMiast(); 
	// Metoda, kt�ra zwraca dystans z miasta do miasta
	int getDystans(int i, int j);  

};
