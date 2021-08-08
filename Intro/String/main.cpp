#include "String.h"

#define tab "\t"

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