#include <iostream>
#include <string>

struct Fraction
{
    int numerator;
    int denominator = 1;
};

void multiply(Fraction x, Fraction y)
{
    using namespace std;

    double res = static_cast<double>(x.numerator * y.numerator) / (x.denominator * y.denominator);

    cout << "Result = " << res << endl;
}

int main()
{
    Fraction num1{ 5, 4 };
    Fraction num2{ 9, 15 };

    multiply(num1, num2);
    
    return 0;
}