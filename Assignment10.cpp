#include <iostream>
using namespace std;

class String
{
	friend String operator+ (const String& str1, const String& str2);
	friend istream& operator>>(istream& in, String& str);
	friend ostream& operator<<(ostream& out, String& str);

public:
	char* str;
};

istream& operator>>(istream& in, String& Str)
{	
	Str.str = new char[50];
	in >> Str.str;
	return in;
}

ostream& operator<<(ostream& out, String& Str)
{
	out << Str.str;
	return out;
}

String operator+ (const String& str1, const String& str2)
{
	strcat(str1.str, str2.str);
	return str1;
}

int main()
{
	String Str1, Str2;
    cout << "Input String 1: ";
	cin >> Str1;
	cout << "Input String 2: ";
	cin >> Str2;
	Str1 = Str1 + Str2;
	cout << "String concatenation: " << Str1;
}
