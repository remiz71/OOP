#include <iostream>
using namespace std;
#define tab "\t"

class Fraction; //обьявление класса
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

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
	explicit Fraction(int integer)
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
	Fraction operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction operator-=(const Fraction& other)
	{
		return *this = *this - other;
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
	Fraction& operator--() // Prefix increment
	{
		integer--;
		return *this;
	}
	Fraction operator--(int) //PostFix increment
	{
		Fraction old = *this; // save the old value CopyConstructor
		integer--;
		return old; //CopyConstructor

	}

	// Type-cast operators:


	operator int()
	{
		return integer;
	}


	//  methods
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
		{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
		}
	Fraction inverted()
	{
		to_improper();
		/*int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;*/
		return Fraction(denominator, numerator);

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
// Арифметика
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
Fraction operator+(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return Fraction
		(
			(left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()),
			left.get_denominator() * right.get_denominator()
		).to_proper();
		
	}
Fraction operator-(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return Fraction
		(
			(left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()),
			left.get_denominator() * right.get_denominator()
		).to_proper();
		
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_reverse();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		left.get_denominator()* right.get_numerator()
	);*/
	return left * right.inverted();
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator() == right.get_numerator() &&
		left.get_denominator() == right.get_denominator())
		return true;
	else return false;
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction temp = left * right.inverted();
	if (temp.get_numerator() > temp.get_denominator())
		return true;
	else return false;
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction temp = left * right.inverted();
	if (temp.get_numerator() < temp.get_denominator())
		return true;
	else return false;
}
bool operator<=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction temp = left * right.inverted();
	if (temp.get_numerator() < temp.get_denominator() || 
		temp.get_numerator() == temp.get_denominator()
		)
		return true;
	else return false;
}
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction temp = left * right.inverted();
	if (temp.get_numerator() > temp.get_denominator() ||
		temp.get_numerator() == temp.get_denominator()
		)
		return true;
	else return false;
}
bool operator!=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator() != right.get_numerator() &&
		left.get_denominator() != right.get_denominator())
		return true;
	else return false;
}


//#define CONSTRUCTORS_CHECK
//#define INCREMENT_CHECK
//#define ARIFMETICAL_OPERATORS_CHECK
#define OPTIMIZATION_CHECK
//#define TYPE_CONVERSION
#define TYPE_COVERSIONS_HOME_WORK

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
#ifdef ARIFMETICAL_OPERATORS_CHECK
	Fraction A(2, 3,4);
	Fraction B(3, 4,5);
	Fraction C = A - B;
	Fraction E = A + B;
	Fraction D 
	C.print();
	D.print();
	E.print();
	(A + B).print();

#endif // ARIFMETICAL_OPERATORS_CHECK
#ifdef INCREMENT_CHECK

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
#endif // INCREMENT_CHECK
#ifdef OPTIMIZATION_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	if (A >= B) cout << "bolshe ";
	else cout << " menshe  " ;
	A.print();

#endif // OPTIMIZATION_CHECK
#ifdef TYPE_COVERSION
	//int a = 2;      //no conversint
//double b = 3;   //from int to double
//int c = 4.5;    //from double to int (possible loss of data)
//int d = b;      //from double to int (no data loss)
//double e = 5.3;
//int f = a + e;

	int a = 2;
	Fraction A = (Fraction)5;
	A.print();//From int to Fraction (forom less to more)
	Fraction B;
	B = (Fraction)3;
	B.print();
	int b = B;
	cout << b << endl;
#endif // TYPE_CONVERSION
#ifdef TYPE_CONVERSION_HOME_WORK






#endif // TYPE_CONVERSION_HOME_WORK






}