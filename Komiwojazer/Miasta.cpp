#include "Miasta.h"


Miasta::Miasta(const std::string& nazwa_pliku)
{
	if (nazwa_pliku == "brak") { throw - 1; }
	std::ifstream file(nazwa_pliku);

	if (file.good())
		file >> liczba_miast;

	// wype³nianie macierzy zerami
	tablica.resize(liczba_miast); 
	for (int i = 0; i < liczba_miast; ++i)
	{
		tablica[i].resize(liczba_miast);
	}

	while (file.good())
	{
		for (int i = 0; i < liczba_miast; ++i)
		{
			for (int j = 0; j < liczba_miast; ++j)
			{
				// zapisywanie z pliku do macierzy
				file >> tablica[i][j];  
			}
		}

	}
	file.close();

}

Miasta::~Miasta() {}

int Miasta::getLiczbaMiast()
{
	return this->liczba_miast;
}


int Miasta::getDystans(int i, int j)
{
	return this->tablica[i][j];
}
