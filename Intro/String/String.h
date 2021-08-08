#pragma once
#include <iostream>
#include <string>

using namespace std;

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
private:
	unsigned int length; //Размер строки в байтах
	char* str; // Указатель на строку в динамической памяти
public:
	unsigned int get_length()const;
	const char* get_str()const;
	char* get_str();
	explicit String(unsigned int length = 80);
	String(const char* str);
	String(const String& other);
	~String();

	//Operators:
	String& operator+=(const String& other);

	String& operator=(const String& other);
	const char& operator[](unsigned int i)const;
	char& operator[](unsigned int i);
	// Methods:

	void print()const;
	

};