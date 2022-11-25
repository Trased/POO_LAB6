#include "persoana.h"
#pragma warning(disable : 4996)
Persoana::Persoana(char* nume, char* prenume, Data* dataNastere)
{
	this->nume = new char[strlen(nume) + 1];
	this->prenume = new char[strlen(prenume) + 1];
	this->dataNastere = new Data(*dataNastere);
	strcpy(this->nume, nume);
	strcpy(this->prenume, prenume);
}
Persoana::~Persoana()
{
	delete[] nume;
	delete[] prenume;
	delete dataNastere;
}
char* Persoana::getNume()
{
	return nume;
}
char* Persoana::getPrenume()
{
	return prenume;
}
Data* Persoana::getDataNastere()
{
	return dataNastere;
}
void Persoana::afisarePersoana()
{
	cout << nume << " " << prenume << ", data nastere: " << dataNastere->getAn() << "." << dataNastere->getLuna() << "." << dataNastere->getZi();
}
void Persoana::afisare()
{
	afisarePersoana();
	cout << endl;
}
Persoana& Persoana::operator=(const Persoana& src)
{
	if (this->nume != nullptr)
	{
		delete[] this->nume;
	}
	if (this->prenume != nullptr)
	{
		delete[] this->prenume;
	}
	if (this->dataNastere != nullptr)
	{
		delete this->dataNastere;
	}
	this->nume = new char[strlen(src.nume) + 1];
	this->prenume = new char[strlen(src.prenume) + 1];
	this->dataNastere = new Data(*src.dataNastere);
	strcpy(this->nume, src.nume);
	strcpy(this->prenume, src.prenume);
	return *this;
}
