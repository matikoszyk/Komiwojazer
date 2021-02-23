#pragma once
#include "Miasta.h"
#include "Trasa.h"
#include "Populacja.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>



int main(int argc, char ** argv)
{
	srand(time(NULL));
	system("cls");
	int rozmiar_populacji = 10;
	std::string plik = "brak";
	int petla = 100;
	float prawdopodobienstwo_mutacji = 0;
	int tmp = 0;
	if (argc > 1)
	{
		for (int i = 0; i < argc; ++i)
		{
			tmp = i + 1;
			if ((argv[i][0] == '-') && (argv[i][1] == 'r'))
				rozmiar_populacji = atoi(argv[tmp]);
			if ((argv[i][0] == '-') && (argv[i][1] == 'm'))
				prawdopodobienstwo_mutacji = atof(argv[tmp]);
			if ((argv[i][0] == '-') && (argv[i][1] == 'i'))
				petla = atoi(argv[tmp]);
			if ((argv[i][0] == '-') && (argv[i][1] == 'p'))
				plik = argv[tmp];

		}
	}



	try
	{
		Miasta miasta(plik);
		Trasa trasa1(miasta.getLiczbaMiast());
		Populacja populacja1(rozmiar_populacji, trasa1, miasta);
		std::cout << "Populacja startowa: " << std::endl;
		populacja1.wyswietl_populacje();
		std::cout << std::endl << "Najkrotsza trasa na poczatku: " << std::endl;
		populacja1.wyswietl_najkrotsza();
		//Aktualnie najkrótsza trasa (do tej pory)
		int aktualna_najkrotsza; 
		//Pêtla w której wyst¹pi³a najkrotsza trasa
		int najkrotsza_index; 
		for (int i = 0; i < petla; ++i)
		{
			populacja1.Selekcja();
			populacja1.KrzyzowaniePMX(miasta);
			populacja1.Mutacja(miasta, prawdopodobienstwo_mutacji);
			if (i == 0)
			{
				aktualna_najkrotsza = populacja1.get_najkrotsza();
				najkrotsza_index = i;
			}
			else if (populacja1.get_najkrotsza() < aktualna_najkrotsza)
			{
				aktualna_najkrotsza = populacja1.get_najkrotsza();
				najkrotsza_index = i;
			}
		}

		
		std::cout << std::endl << "Najkrotsza trasa: " << aktualna_najkrotsza << ", po " << najkrotsza_index << " iteracji" << " z " << petla << std::endl;


	}
	catch (int kod)
	{
		if (kod == -1)
		{
			std::cout << "Nie podales sciezki do pliku. Wczytaj plik parametrem -p " << std::endl;
			std::cout << std::endl << "--------------------------" << std::endl << std::endl;
			std::cout << "Parametry programu:" << std::endl
				<< "-p -sciezka do pliku" << std::endl
				<< "-r -rozmiar populacji" << std::endl
				<< "-i -liczba iteracji" << std::endl
				<< "-m -prawdopodobienstwo mutacji (0,1)" << std::endl << std::endl
				<< "Przyklad:  " << argv[0] << " -p komiwoj.txt -s 20 -i 10000 -m 0.2" << std::endl;
		}
	}


	system("pause");
	return 0;
}
