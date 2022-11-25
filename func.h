#pragma once
#include <iostream>
using namespace std;

class Complex {
	int re, im;
public:
	Complex();
	Complex(int, int);
	void afisare();
	void citire();
	friend Complex operator+(Complex, Complex);
	friend Complex operator-(Complex, Complex);
	friend Complex operator*(Complex, Complex);
	friend bool operator==(Complex, Complex);
	double operator~();
};

class Multime {
	int* date;
	int dim;
	int n;
public:
	Multime();
	Multime(int dim);
	~Multime();
	void adauga(int num);
	void extrage(int num);
	void afisare();
	Multime(const Multime&);
	Multime& operator+=(int);
	Multime& operator-=(int);
	Multime& operator =(const Multime&);
	Multime& operator +=(const Multime&);
	Multime operator +(const Multime&);
};

class String {
	char* propozitie;
public:
	String();
	String(char*);
	String(const String&);
	String operator+(const String&);
	String operator=(const String&);
	friend bool operator==(const String,const String);
	int cauta(String);
	void afisare();
	void scriere();
	int compara(String);
};
