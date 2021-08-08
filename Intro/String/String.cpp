// Делегирование конструкторов
//
#include"String.h"

#define tab "\t"

unsigned int String::get_length()const
{
	return length;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
String::String(unsigned int length) :length(length), str(new char[length] {})
{
	cout << "DefaultConst: " << tab << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	for (int i = 0; i < length; i++)this->str[i] = str[i];
	cout << "1ArgConst:" << tab << this << endl;
}
String::String(const String& other) : String(other.str)
{
	cout << "CopyConstr:" << tab << this << endl;
}
String::~String()
{
	delete[] this->str; //[] - удаление массива
	cout << "Destructor:\t" << this << endl;
}

//Operators:
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

String& String::operator=(const String& other)
{
	// 0. Проверяем , является ли принятый обьект - нашим
	if (this == &other)return *this;

	// 1. Освобождаем память, занимаемую старым значением
	delete[] this->str;
	// 2. Выполняем deep copy
	this->length = other.length;
	this->str = new char[length] {};
	for (int i = 0; i < length; i++)this->str[i] = other.str[i];
	cout << "CopyAssigment:" << tab << this << endl;
	return *this;
}
const char& String::operator[](unsigned int i)const
{
	return str[i];
}
char& String::operator[](unsigned int i)
{
	return str[i];
}
// Methods:

void String::print()const
{
	cout << "Size:" << tab << length << endl;
	cout << "Str:" << tab << str << endl;
}
String operator+(const String& left, const String& right)
{
	String cat(left.get_length() + right.get_length() - 1);
	for (int i = 0; i < left.get_length(); i++)
	{
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_length(); i++)
	{
		cat[i + left.get_length() - 1] = right[i];
	}
	return cat;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}