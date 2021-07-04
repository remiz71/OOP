#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "\n-----------------------------------------------"
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define CONSTRUCTORS_OVERLOADING

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double Length(double x, double y)
	{
		double l;
		l = sqrt(x * x + y * y);
		return l;
	}

	/////////////////////////////////// Constructors:

	Point() //����������� ��-���������
	{
		x = y = 0;
		cout << "DefaultConstructor: \t\t" << this << endl;
	}
	Point(double x) //����������� � ����� ����������
	{
		this->x = x;
		this->y = 0;
		cout << "Single_Argument_Constructor: \t\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: \t\t" << this << endl;
	}
	Point(const Point& other) //������������� ����������� ������� Shallow copy
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy_Constructor: \t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	////////////////////Operators:
	Point& operator= (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy_Assignment: \t\t" << this << endl;
		return *this;
	}

	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;

	}

};
	double A_length_B(Point A, Point B);


/*
�������� ��������� ��� ����� �� ������� ��� ������.
*/
//#define STRUCT_POINT
int main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT


	int a; //��������� ���������� "�" ���� "int"
	// �������� �������
	Point A; // ��������� ���������� "�" ���� Point
			 // ��������� ������ "�" ��������� "Point"
			 // ������� ��������� "�" ��������� "Point"
	// ������ ������ ��� ��������� �������� ����������� (instance) ������ ��� ���������
	// Instantiate - ������� ��������� ��� ������
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;

#endif // STRUCT_POINT
/*
��������� � ����� ��������

��� ��������� � ����� �������� ����� ������������ .(�������� ������� �������)
. - ������������ ��� ������� � ����� ������� �� ����� �������
���� ->  - �������� ���������� ������� ( Arrow operator) 
������������ ��� ������� �� ������ � ����� ���������

��������� ���

1.������������
2.������������
3.�����������
________________________________________

������������ (Encapsulation) - ��� �������� ������������ ����� ������ �� �������� ����
����������� �������������� �������:
private: ���� �������� ��������� , �������� ������ ������ ������ � ���������� �� ��������� ������
� ��������� ������ ����������� ������ ���� ���������� ����� ������, ��� �������� �� �� ��������� ����������
public: �������� ����, �������� �� ������ ����� ���������. � ������ ������ ������ ��������� ������
protected: ���� ����������� ������������ ������ ��� ������������. �������� ������ ������ ������ ������ � ��� ��������� �������.

!!!!!!����������!!!!!!

����������� �������� ����� ������� � ���������� �������� ��, ��� � ������ ��� ���� ��������, ���� �� ������� ��������
� � ��������� ��� ���� �������, ���� �� ������� ��������


get/set ������

���� ���������� � ������� ������� ���, ��� �� ������ ������������, �� �� ��� ��� �������� ������
������� � ������ ���������� � ������ ������ ���� ���� get-����� � set-�����
get(��������) - ��������� ������ � ���������� �� ������
set(������) -   ��������� ������ � ���������� �� ������
�� ����� ���� set-������ ������������ ���������� ������, ���� ��� �����.
������������ �������� ������� �� ���������� ��������� � �� ������ � ��� ����������� ��������.

����� ����� ���� ������ ������ ��� �������. ��� ������ ������ ���� ������������ - �����, ������� �� �������� ������ ��� �������� �� ����������

This - ��������� �� ������ ��� �������� ���������� �����. ������ ������ ���������� ������ ��� �������, ��� �������� ����� ��������.
�� ������ ����� ������ ����� �������, ��� ������ this.

� ����� ������ ����������� ������ ����:
Constructor - �����,������ ������� ������
~Destructor - �����, ������� ���������� ������ �� ���������� ��� ������� �����.
����� ����� ������� �������� ��� ���������� � ������� ��������� � ������� �� ��������, �������� � ��������� ��������
��������: 
Operator=

����������� � ���������� ���������� ��� �� ��� ����� �� ����� ������������ �������� ~ 
����������� ����� ��������� ���������. ������� ��� ��� � ����� ������ ������� ����� �����������
� ������ ����� ���� ������� ������ �������������
���������� �� ����� �������� ���������, ��� ������ �����������, ������� � ������ ����� ���� ������ ���� ����������
*/
	Point A;
	Point B;
	A.set_x(2);
	A.set_y(3);
	B.set_x(4);
	B.set_y(2);
	cout << "���������� �� ����� �: " << A.Length(A.get_x(), A.get_y()) << endl;
	cout << "���������� ����� ������� � � �: " << A_length_B(A, B) << endl;

	for (int i = 0; i < 5; i++) //i-��������� ������ ��� ����� for
	{
		cout << i << tab;
	}
	cout << endl;
#ifdef CONSTRUCTORS_CHECK
	Point A; //���������� default constructor
	A.print();
	Point B = 3;// ����������� � ����� ����������
	B.print();
	Point C(2, 3);
	C.print();
	Point D = C; //Copy Constructor
	D.print();
	Point E; //Default Constructor
	E = C;  //Copy Assignment
	E.print();
#endif CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK

	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	cout << "\n----------------------------------------\n";
	A = B = C = Point(4, 5);
	cout << "\n----------------------------------------\n";
	A.print();
	B.print();
	C.print();

#endif ASSIGNMENT_CHECK


	
	return 0;
}

double A_length_B(Point A, Point B)
{
	double Len;
	Len = sqrt((A.get_x() - B.get_x()) * (A.get_x() - B.get_x()) + (A.get_y() - B.get_y()) * (A.get_y() - B.get_y()));
	return Len;
}



#ifdef CONSTRUCTORS_CHECK
	Point A; //���������� default constructor
	A.print();
	Point B = 3;// ����������� � ����� ����������
	B.print();
	Point C(2, 3);
	C.print();
	Point D = C; //Copy Constructor
	D.print();
	Point E; //Default Constructor
	E = C;  //Copy Assignment
	E.print();
#endif CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK

	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	cout << "\n----------------------------------------\n";
	A = B = C = Point(4, 5);
	cout << "\n----------------------------------------\n";
	A.print();
	B.print();
	C.print();

#endif ASSIGNMENT_CHECK
