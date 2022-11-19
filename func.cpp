#include "func.h"
Complex::Complex()
{
	this->re = 0;
	this->im = 0;
}

Complex::Complex(int re, int im)
{
	this->re = re;
	this->re = im;
}
void Complex::afisare()
{
	if (this->im)
	{
		cout << this->re << "+i*" << this->im << "\n";
	}
	else
	{
		cout << this->re << "\n";
	}
}
void Complex::citire()
{
	cout << "Re=";
	cin >> this->re;
	cout << "Im= ";
	cin >> this->im;
}
Complex operator+(Complex a, Complex b)
{
	Complex rez;
	rez.re = a.re + b.re;
	rez.im = a.im + b.im;
	return rez;
}
Complex operator-(Complex a, Complex b)
{
	Complex rez;
	rez.re = a.re - b.re;
	rez.im = a.im - b.im;
	return rez;
}
Complex operator*(Complex a, Complex b)
{
	Complex rez;
	rez.re = a.re * b.re - a.im * b.im;
	rez.im = a.im * b.re + a.re * b.im;
	return rez;
}
bool operator==(Complex a, Complex b)
{
	if (a.re == b.re && a.im == b.im)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
double Complex::operator~()
{
	double rez;
	rez = sqrt(pow(this->re, 2) + pow(this->im, 2));
	return rez;
}

Multime::Multime()
{
	this->dim = 50;
	this->n = 0;
	date = new int[this->dim];
}
Multime::Multime(int dim)
{
	this->dim = dim;
	this->n = 0;
	date = new int[this->dim];
}
Multime::~Multime()
{
	if (this->date != NULL)
	{
		delete[] date;
	}
}
void Multime::adauga(int num)
{
	if (n == 0)
	{
		date[n] = num;
		n++;
	}
	else {
		if (n < dim)
		{
			int contor = 0;
			for (int i = 0; i < n; i++)
			{
				if (date[i] == num)
				{
					contor = 1;
					break;
				}
			}
			if (contor)
			{
				cout << "\nNumarul " << num << " este deja in multime\n";
			}
			else
			{
				date[n] = num;
				n++;
			}
		}
		else {
			cout << "\nNu mai este loc in multime\n";
		}
	}
}
void Multime::extrage(int num)
{
	if (n == 0)
	{
		cout << "\nMultimea nu are elemente\n";
	}
	else {
		if (n < dim)
		{
			int temp = 0;
			for (int i = 0; i < n; i++)
			{
				if (date[i] == num)
				{
					date[i] = date[n - 1];
					n--;
					temp = 1;
				}
			}
			if (temp == 0)
			{
				cout << "\nNumarul " << num << " nu apartine multimii\n";
			}
		}
	}
}
void Multime::afisare()
{
	for (int i = 0; i < n; i++)
	{
		cout << date[i] << " ";
	}
}
Multime::Multime(const Multime& a)
{
	this->date = new int[dim];
	this->dim = a.dim;
	this->n = a.n;
	for (int i = 0; i < a.n; i++)
	{
		this->date[i] = a.date[i];
	}

}
Multime& Multime::operator+=(int a)
{
	this->adauga(a);
	return *this;
}
Multime& Multime::operator-=(int a)
{
	this->extrage(a);
	return *this;
}
Multime& Multime::operator =(const Multime& a)
{
	delete[]this->date;
	date = 0;
	this->date = new int[a.dim];
	this->n = a.n;
	this->dim = a.dim;
	for (int i = 0; i < a.n; i++)
	{
		this->date[i] = a.date[i];
	}
	return *this;
}
Multime& Multime::operator +=(const Multime& a)
{
	Multime temp;
	temp.date = new int[this->dim];
	temp.dim = this->dim;
	temp.n = this->n;
	for (int i = 0; i < temp.n; i++)
	{
		temp.date[i] = this->date[i];
	}

	delete[] this->date;
	this->dim = this->dim + a.dim;
	this->date = new int[this->dim];
	this->n = 0;
	int cont = temp.n + a.n;

	for (int i = 0; i < cont; i++)
	{
		if (i < temp.n)
		{
			*this += temp.date[i];
		}
		else
		{
			*this += a.date[i-temp.n];
		}
	}
	return *this;
}
Multime Multime::operator +(const Multime& a)
{
	Multime temp;
	temp.date = new int[this->dim+a.dim];
	temp.dim = (this->dim+a.dim);
	temp.n = 0;
	int cont = this->n + a.n;
	for (int i = 0; i < cont; i++)
	{
		if (i < this->n)
		{
			temp +=this->date[i];
		}
		else
		{
			temp += a.date[i - this->n];
		}
	}
	return temp;
}

String::String()
{
	this->propozitie = new char[100];
}
String::String(char* cuv)
{
	this->propozitie = new char[strlen(cuv)+2];
	strcpy_s(this->propozitie,(strlen(cuv)+1),cuv);
}
/*
String::~String()
{
	if (this->propozitie)
	{
		delete[] propozitie;
	}
}

String::String(const String& cuv)
{
	this->propozitie = new char[strlen(cuv.propozitie)+2];
	strcpy_s(this->propozitie, (strlen(this->propozitie)+1), cuv.propozitie);
}
*/
String String::operator+(const String& cuv)
{
	String temp;
	temp.propozitie = new char[strlen(this->propozitie) + strlen(cuv.propozitie)+40];
	int cont = strlen(this->propozitie) + strlen(cuv.propozitie)+1;
	for (int i=0; i < cont; i++)
	{
		if (i < strlen(this->propozitie))
		{
			temp.propozitie[i] =this->propozitie[i];
		}
		else
		{
			temp.propozitie[i] = cuv.propozitie[i- strlen(this->propozitie)];
		}
	}

	return temp;
}
String String::operator=(const String& cuv)
{
	delete[] this->propozitie;
	this->propozitie = new char[strlen(cuv.propozitie) + 2];
	strcpy_s(this->propozitie, (strlen(cuv.propozitie)+1), cuv.propozitie);
	return *this;
}
bool operator==(const String unu, const String doi)
{
	if (strlen(unu.propozitie) != strlen(doi.propozitie))
	{
		return 1;
	}
	for (int i = 0; i < strlen(unu.propozitie); i++)
	{
		if (unu.propozitie[i] != doi.propozitie[i])
		{
			return 1;
		}
	}
	return 0;
}
int String::cauta(String cuv)
{
	if (strlen(this->propozitie) < strlen(cuv.propozitie))
	{
		cout << "Cautare eronata\n";
		return -1;
	}
	int cont = strlen(this->propozitie) - strlen(cuv.propozitie);
	int dif = 0;
	int poz = 0;
	for (int k = 0; k < cont; k++)
	{
		if (this->propozitie[k] == cuv.propozitie[0])
		{
			if ((strlen(this->propozitie) - k) < strlen(cuv.propozitie))
			{
				return -1;
			}
			poz = k;
			dif = 0;
			for (int j = 0; j < strlen(cuv.propozitie)-1; j++)
			{
				if (this->propozitie[k+j] != cuv.propozitie[j])
				{
					dif = 1;
					break;
				}
			}

		}
	}
	if (dif == 0)
	{
		return poz;
	}
	else
	{
		return -1;
	}
}
void String::afisare()
{
	cout << this->propozitie;
}
int String::compara(String cuv)
{
	if (strlen(this->propozitie) < strlen(cuv.propozitie))
	{
		return -1;
	}else
	{
		if (strlen(this->propozitie) == strlen(cuv.propozitie))
		{
			return 0;
		}
		else {
			return 1;
		}
	}
}
void String::scriere()
{
	delete[] this->propozitie;
	this->propozitie = new char[100];
	cout << "Introduceti sirul de caractere: ";
	cin >> this->propozitie;
}