#include <iostream>
#include <string>
using namespace std;
#define tab "\t"

class String
{
private:
	int length;
	char* strg;
public:
	int get_length()const
	{
		return length;
	}
	string get_string()const
	{
		return strg;
	}
	String()
	{
		this->strg = new char[length];
		cout << "DefaultConstruct: " << this << endl;
		cout << sizeof(strg) << endl;
	}
	String(const char strg[])
	{
		this->length = strlen(strg) + 1;
		this->strg = new char[length] ;
		for (int i = 0; strg[i]; i++)
		{
			this->strg[i] = strg[i];
		}
		cout << "Const:" << tab << this << endl;
	}
	~String()
	{
		cout << "Destructor:\t" << this << endl;
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
	String str;
	String str1{ "Hello" };
	String str2{ "World" };
	cout << str1 << endl;
	cout << str2 << endl;
	

}
