#include <iostream>
#include <string>
using namespace std;
#define tab "\t"

class String
{
private:
	unsigned int length; //Размер строки в байтах
	char* str; // Указатель на строку в динамической памяти
public:
	int get_length()const
	{
		return length;
	}
	string get_string()const
	{
		return str;
	}
	explicit String(unsigned int length=80)
	{
		this->length = length;
		this->str = new char[length] {};
		cout << "DefaultConstruct: " << this << endl;
	}
	String(const char* str)
	{
		/*while (str[length++]);*/
		this->length = strlen(str) + 1; //this->length хранит размер в байтах
										//а strlen() считает в символах
		this->str = new char[length] {};
		for (int i = 0; i < length; i++)this->str[i] = str[i];
		cout << "1ArgConst:" << tab << this << endl;
	}
	~String()
	{
		delete[] this->str; //[] - удаление массива
		cout << "Destructor:\t" << this << endl;
	}

	// Methods
	void print()const
	{
		cout << "Size:" << tab << length << endl;
		cout << "Str:" << tab << str <<endl;
	}
	String& operator=(const String& other)
	{
		
	}
};

ostream& operator<< (ostream & os, const String & obj)
{
	return os << obj.get_string();
}
int main()
{
	setlocale(LC_ALL, "Russian");
	//String str = 5; //Implicit Conversion from int to String
	String str(5);  // explicit constructor можно вызвать только так
					// и нельзя вызвать =
	str.print();
	String str1 = "Hello";
	str1.print();
	
	

}
