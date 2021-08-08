#include <iostream>
#include <string>
using namespace std;
#define tab "\t"

class String;
String operator+(const String& left, const String& right);


class String
{
private:
	unsigned int length; //Размер строки в байтах
	char* str; // Указатель на строку в динамической памяти
public:
	unsigned int get_length()const
	{
		return length;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	explicit String(unsigned int length=80):length(length),str(new char[length] {})
	{
		cout << "DefaultConst: " <<tab<<  this << endl;
	}
	String(const char* str):length(strlen(str)+1),str(new char[length] {})
	{
		for (int i = 0; i < length; i++)this->str[i] = str[i];
		cout << "1ArgConst:" << tab << this << endl;
	}
	String(const String& other):length(other.length), str(new char[length] {})
	{
		for (int i = 0; i < length; i++)this->str[i] = other.str[i];
		cout << "CopyConstr:" << tab << this << endl;
	}
	~String()
	{
		delete[] this->str; //[] - удаление массива
		cout << "Destructor:\t" << this << endl;
	}

	//Operators:
String& operator+=(const String& other)
{
	return *this = *this + other;
}

	String& operator=(const String& other)
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
	const char& operator[](unsigned int i)const
	{
		return str[i];
	}
	char& operator[](unsigned int i)
	{
		return str[i];
	}
	// Methods:

	void print()const
	{
		cout << "Size:" << tab << length << endl;
		cout << "Str:" << tab << str <<endl;
	}
	

};
String operator+(const String& left, const String& right)
{
	String cat(left.get_length() + right.get_length() - 1);
	for (int i = 0; i < left.get_length(); i++)
	{
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0;i<right.get_length(); i++)
	{
		cat[i+left.get_length() - 1] = right[i];
	}
	return cat;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
int main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	int a = 2;
	int b = 3;
	a = b;

	//String str = 5; //Implicit Conversion from int to String
	String str(5);  // explicit constructor можно вызвать только так
					// и нельзя вызвать =
	str.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();

	String str2 = str1;
	str2.print();

	String str3;
	str3 = str2;
	str3.print();
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	cout << "\n------------------------\n" << endl;
	String str3 = str1 + " " + str2;
	cout << "\n------------------------\n" << endl;
	cout << str1+str2 << endl;
	cout << "\n------------------------\n" << endl;
	str1 += str2;
	cout << "\n------------------------\n" << endl;


	
	

}