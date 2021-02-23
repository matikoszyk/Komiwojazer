#include "Populacja.h"


std::default_random_engine gen;
std::uniform_real_distribution<float> dist(0, 1);


Populacja::Populacja(int rozmiar, Trasa& trasa, Miasta& miasta)
{
	popul.resize(rozmiar);
	dystans.resize(rozmiar);
	for (int i = 0; i < rozmiar; ++i)
	{
		trasa.losowa_trasa();
		popul[i] = trasa;
		dystans[i] = popul[i].dystans(miasta);
	}

}

Populacja::~Populacja(){};

void Populacja::wyswietl_populacje()
{
	for (int i = 0; i < popul.size(); ++i)
	{
		popul[i].wyswietl_trase();
		std::cout << "dlugosc trasy: " << dystans[i] << std::endl;
	}
}

void Populacja::wyswietl_najkrotsza()
{
	int tmp = 0;
	int najkrotsza_trasa = dystans[0];
	for (int i = 1; i < popul.size(); ++i)
	{
		if (dystans[i] <= najkrotsza_trasa)
		{
			najkrotsza_trasa = dystans[i];
			tmp = i;
		}
	}
	popul[tmp].wyswietl_trase();
	std::cout << "dlugosc trasy: " << najkrotsza_trasa <<  std::endl;
}

int Populacja::get_najkrotsza()
{
	int tmp = 0;
	int najkrotsza_trasa = dystans[0];
	for (int i = 1; i < popul.size(); ++i)
	{
		if (dystans[i] <= najkrotsza_trasa)
		{
			najkrotsza_trasa = dystans[i];
			tmp = i;
		}
	}
	return najkrotsza_trasa;

}


void Populacja::Selekcja()
{

	std::vector<Trasa> populacja_n(popul.size());
	std::vector<float> prawdopodobienstwo(popul.size());
	std::vector<float> rozklad(popul.size());
	std::vector<int> odleglosci_n(popul.size());
	float odleglosc_wszystkich = 0;
	float odlegosc_trasy = 0;
	float prawdopodobienstwo_trasy = 0;

	// Sumowanie d³ugoœci wszystkich tras
	for (int i = 0; i < popul.size(); ++i)
	{
		odleglosc_wszystkich += dystans[i];
	}

	//Wyliczanie prawdopodobieñstwa pojawienia siê trasy w nowej populacji
	for (int i = 0; i < popul.size(); ++i)
	{
		odlegosc_trasy = dystans[i];
		prawdopodobienstwo_trasy = (1 - (odlegosc_trasy / odleglosc_wszystkich)) / (prawdopodobienstwo.size() - 1);
		prawdopodobienstwo[i] = prawdopodobienstwo_trasy;
	}

	rozklad[0] = prawdopodobienstwo[0];
	for (int i = 1; i < popul.size(); ++i)
	{
		rozklad[i] = rozklad[i - 1] + prawdopodobienstwo[i];
	}


	float losowa = 0;
	for (int i = 0; i < popul.size(); ++i)
	{
		losowa = dist(gen);


		for (int j = 0; j < popul.size(); ++j)
		{
			if (losowa <= rozklad[j])
			{
				populacja_n[i] = popul[j];
				odleglosci_n[i] = dystans[j];
				break;
			}
		}
	}

	popul = populacja_n;
	dystans = odleglosci_n;


}

void Populacja::KrzyzowaniePMX(Miasta& miasta)
{


	for (int rodzic = 0; rodzic < (popul.size() / 3); rodzic += 2)
	{

		int rodzic2 = rodzic + 1;
		int rozmiar = popul[rodzic].rozmiar_trasy();
		//losowanie liczb z przedzia³u <0,rozmiar>
		std::uniform_int_distribution<int> dist_int(0, rozmiar);

		int lewy = (dist_int(gen)); 
		int prawy = 0;
		while (true)
		{
			//losowanie liczby e w przedziale <0, rozmiar>
			prawy = (dist_int(gen)); 
			if (prawy != lewy) break;
		}
		int tmp = 0;
		// je¿eli lewa wiêksza to zamiana
		if (lewy > prawy) 
		{
			tmp = lewy;
			lewy = prawy;
			prawy = tmp;
		}

		std::vector<int> tablica1(rozmiar,-1);
		std::vector<int> tablica2(rozmiar,-1);

		std::vector<int> dziecko(rozmiar,-2);
		std::vector<int> dziecko2(rozmiar,-2);

		for (int i = 0; i < rozmiar; ++i)
		{
			dziecko[i] = popul[rodzic].getNumerMiasta(i);
			dziecko2[i] = popul[rodzic2].getNumerMiasta(i);
		}

		int tmp1 = 0;
		for (int i = 0; i < rozmiar; ++i)
		{
			if ((i >= lewy) && (i <= prawy))
			{
				tmp1 = dziecko[i];
				dziecko[i] = dziecko2[i];
				dziecko2[i] = tmp1;

				tablica1[i] = dziecko[i];
				tablica2[i] = dziecko2[i];
			}

		}

		int tmp2 = 0;
		// poszukiwanie duplikató w tablicy
		for (int i = 0; i < rozmiar; ++i)  
		{
			if ((i<lewy) || (i>prawy))
			{
				tmp1 = dziecko[i];
				while (true)
				{
					auto it = find(tablica1.begin(), tablica1.end(), tmp1);
					if (it == tablica1.end())
					{
						break;
					}
					else
					{
						for (int j = 0; j < rozmiar; ++j)
						{
							if (tablica1[j] == *it)
							{
								tmp2 = j;
								break;
							}
						}
						dziecko[i] = tablica2[tmp2];
						tmp1 = dziecko[i];
					}
				}
			}
		}
		// poszukiwanie duplikatów w drugiej tablicy
		for (int i = 0; i < rozmiar; ++i)  
		{
			if ((i<lewy) || (i>prawy))
			{
				tmp1 = dziecko2[i];
				while (true)
				{
					auto it = find(tablica2.begin(), tablica2.end(), tmp1);
					if (it == tablica2.end())
					{
						break;
					}
					else
					{
						for (int j = 0; j < rozmiar; ++j)
						{
							if (tablica2[j] == *it)
							{
								tmp2 = j;
								break;
							}
						}
						dziecko2[i] = tablica1[tmp2];
						tmp1 = dziecko2[i];
					}
				}
			}
		}
		// Aktualizowanie skrzy¿owanych tras
		for (int i = 0; i < rozmiar; ++i) 
		{
			popul[rodzic].jedna_trasa.at(i) = dziecko[i];
			popul[rodzic2].jedna_trasa.at(i) = dziecko2[i];
		}
	}
	// Aktualizowanie odleg³oœci tras
	for (int i = 0; i < popul.size(); ++i) 
	{
		dystans[i] = popul[i].dystans(miasta);
	}

}

void Populacja::Mutacja(Miasta& miasta, float prawdopodobienstwo)
{
	float losowa = 0;
	for (int i = 0; i < popul.size(); ++i)
	{
		losowa = dist(gen);
		// Mutacja wyst¹pi tylko je¿eli prawdopodobieñstwo jest wiêksze ni¿ wylosowana
		if (losowa <= prawdopodobienstwo)
		{
			int rozmiar = popul[i].rozmiar_trasy();
			std::vector<int> mutacja(rozmiar);

			for (int j = 0; j < rozmiar; ++j)
			{
				mutacja[j] = popul[i].getNumerMiasta(j);
			}

			int losowa1 = (rand() % rozmiar);
			int losowa2 = (rand() % rozmiar);
			int tmp = 0;

			tmp = mutacja[losowa1];
			mutacja[losowa1] = mutacja[losowa2];
			mutacja[losowa2] = tmp;

			for (int j = 0; j < rozmiar; ++j)
			{
				popul[i].jedna_trasa.at(j) = mutacja[j];
			}

			dystans[i] = popul[i].dystans(miasta);
		}
	}
}
