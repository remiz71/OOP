#include <iostream>
using namespace std;
#define tab "\t"

class Fraction
{
	int integer;      // Целое
	int numerator;	  //Числитель
	int denominator;  // Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	// constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct: " << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstruct: " << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "2 arg Constructor: " << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;

	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	// Operators 
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment: " << tab << this << endl;
		return *this;
	}

	// increment/Decrement
	Fraction& operator++() // Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int) //PostFix increment
	{
		Fraction old = *this; // save the old value CopyConstructor
		integer++;
		return old; //CopyConstructor

	}


	//  methods
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}
	void to_proper()
		{
		integer += numerator / denominator;
		numerator %= denominator;
		
		}


	void print()const
	{
		if (integer)cout << integer;
		if (integer && numerator)cout << "(";
		if (numerator)cout << numerator << "/" << denominator;
		if (integer && numerator)cout << ")";
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()

	);
}


//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK


	Fraction A; // default constructor
	A.print();
	Fraction B=3; //single-argument constructor
	B.print();
	Fraction C(3, 0);
	C.print();
	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D; //Copy Constructor
	E.print();

	Fraction F; //Default Constructor
	F = E; //CopyAssignment
	F.print();

#endif // CONSTRUCTORS_CHECK
	Fraction A(2, 3,4);
	Fraction B(3, 4,5);
	Fraction C = A * B;
	C.print();

	for (double i = .25; i < 10; i++)
	{
		cout << i << tab;
	}
	cout << endl;

	for (Fraction i(1,4);i.get_integer() <10 ;i++)
	{
		i.print();
	}
	/*B.print();
	A.to_improper();
	A.print();
	A.to_proper();
	A.print();*/




}