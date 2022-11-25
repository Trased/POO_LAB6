#include "func.h"

int main()
{
	int cas;
	cout << "Scopul programului? \n 1: Complex \n 2: Multime \n 3: String\n Case= ";
	cin >> cas;
	switch (cas)
	{
	case 1:
	{
		Complex A;
		Complex B;
		Complex C(0, 0);
		A.citire();
		B.citire();
		C = A - B;
		C.afisare();
		C = A * B;
		C.afisare();
		if (A == B)
		{
			cout << "\nNumerele sunt egale\n";
		}
		else
		{
			cout << "\nNumerele nu sunt egale\n";
		}
		cout << "Modulul numarului este: " << ~A << "\n";
		return 0;
	}
	case 2:
	{
		Multime A;
		Multime B;
		A.adauga(2);
		A.adauga(4);
		A.adauga(6);
		A.adauga(8);
		B.adauga(1);
		B.adauga(3);
		B.adauga(5);
		B.adauga(7);
		B.adauga(9);
		A.afisare();
		cout << "\n";
		B.afisare();
		cout << "\n";
		Multime C;
		C = A;
		C.afisare();
		cout << "\n";
		C += 12;
		C.afisare();
		C -= 3;
		C.afisare();
		cout << "\n";
		C = A;
		C.afisare();
		cout << "\n";
		C += B;
		C.afisare();
		cout << "\n";
		Multime D;
		D = A + B;
		D.afisare();
		return 0;
	}
	case 3:
	{
		
		String B((char*)"ceva");
		String A;
		String C((char*)"ayaye");
		A.scriere();
		C = B + A;
		C.afisare();
		if (C == A)
		{
			cout << "\nsirurile sunt egale\n";
		}
		else
		{
			cout << "\nsirurile sunt diferite\n";
		}
		int cont = B.compara(C);
		switch (cont)
		{
		case -1:
		{
			cout << "\nSirul este mai mic\n";
			break;
		}
		case 0:
		{
			cout << "\nSirurile sunt egale\n";
			break;
		}
		case 1:
		{
			cout << "\nSirul este mai mare\n";
			break;
		}
		}
		cont = C.cauta((char*)"caut");
		if (cont == (-1))
		{
			cout << "subsirul nu se afla in sir";
		}
		else {
			cout << "subsirul se afla la poitia: " << cont;
		}
		return 0;
	}
	default: {
		cout << "Introducere eronata\n";
		return 0;
	}
	}
}
