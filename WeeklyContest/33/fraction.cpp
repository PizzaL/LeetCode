#include <iostream>
#include <sstream>

using namespace std;

int GCD(int a, int b) 
{
	if(b) 
		while ((a %= b) && (b %= a));
	return a + b;
}

int LCM(int a, int b)
{
	return a/GCD(a, b)*b;
}

struct Fraction
{
	int numerator, denominator;
	Fraction()
	: numerator(0), denominator(0)
	{}

	Fraction( int numerator, int denominator)
	: numerator(numerator)
	, denominator(denominator)
	{}

	Fraction operator+(const Fraction& num) const
	{
		int newDenominator = LCM(num.denominator, denominator);
		int newNumerator = newDenominator/denominator*numerator 
						 + newDenominator/num.denominator*num.numerator;
		int gcd = GCD( abs(newDenominator), abs(newNumerator) );
		Fraction res(newNumerator/gcd, newDenominator/gcd);
		return res;
	}
};

ostream& operator<<(ostream& out, const Fraction& num)
{
	out << num.numerator << "/" << num.denominator;
	return out;
}

class Solution {
public:
	
    string fractionAddition(string expression) {
        istringstream sin(expression);
        Fraction res;
        while (!sin.eof() )
        {
        	Fraction num;
        	char slash;
        	sin >> num.numerator >> slash >> num.denominator;
        	if (res.denominator == 0)
        		res = num;
        	else
        		res = res + num;
        }
        ostringstream sout;
        sout << res;
        return sout.str();
    }
};

int main()
{
	string expression = "1/3-1/2";
	Solution solution;
	cout << solution.fractionAddition(expression);
	return 0;
}