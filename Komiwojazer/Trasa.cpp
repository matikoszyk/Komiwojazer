#include "Trasa.h"

Trasa::Trasa() {}

Trasa::Trasa(int rozmiar)
{
	jedna_trasa.resize(rozmiar);
	for (int i = 0; i < rozmiar; ++i)
	{
		jedna_trasa[i] = i;
	}

}


Trasa::~Trasa() {};

void Trasa::losowa_trasa()
{
	std::random_shuffle(jedna_trasa.begin(), jedna_trasa.end());
}

int Trasa::dystans(Miasta& miasta)
{
	int odleglosc_trasy = 0;
	int rozmiar = jedna_trasa.size();

	for (int i = 1; i < rozmiar; ++i)
	{

		odleglosc_trasy += miasta.getDystans(jedna_trasa[i - 1], jedna_trasa[i]);

	}
	odleglosc_trasy += miasta.getDystans(jedna_trasa[rozmiar - 1], jedna_trasa[0]);
	return odleglosc_trasy;
}

void Trasa::wyswietl_trase()
{
	for (int i = 0; i < jedna_trasa.size(); ++i)
	{
		std::cout << jedna_trasa.at(i) << ' ';
	}
}

int Trasa::rozmiar_trasy()
{
	return jedna_trasa.size();
}

int Trasa::getNumerMiasta(int index)
{
	return jedna_trasa.at(index);
}