#include <iostream>
#include <cassert>

class Fraction
{
private:
	int f_num{ 0 };
	int f_div{ 1 };
public:
	Fraction(int num, int div)
		: f_num(num), f_div(div)
	{
		assert(div != 0  && "Error: Denominator is zero!");
	}
	
	friend Fraction operator+(const Fraction& first, const Fraction& second);
	friend Fraction operator+(const Fraction& first, int second);
	//friend Fraction operator+(int first, const Fraction& second);

	friend Fraction operator-(const Fraction& first, const Fraction& second);
	//friend Fraction operator-(const Fraction& first, int second);
	friend Fraction operator-(int first, const Fraction& second);

	friend Fraction operator*(const Fraction& first, const Fraction& second);
	//friend Fraction operator*(const Fraction& first, int second);
	//friend Fraction operator*(int first, const Fraction& second);

	friend Fraction operator/(const Fraction& first, const Fraction& second);
	//friend Fraction operator/(const Fraction& first, int second);
	//friend Fraction operator/(int first, const Fraction& second);

	Fraction operator-() const
	{
		return Fraction(-f_num, f_div);
	}

	int getNum() const { return f_num; }
	int getDiv() const { return f_div; }

	void reduction()
	{
		int less{ f_num < f_div ? f_num : f_div};
		
		if (f_num != 0)
			for (int i = less; i > 1; i--)
				if (!(f_num % i) && !(f_div % i))
				{
					f_num /= i;
					f_div /= i;
					break;
				}
	}

	void print() const
	{
		std::cout << f_num << '/' << f_div << std::endl;
	}
};

bool operator==(const Fraction& first, const Fraction& second)
{
	return static_cast<double>(first.getNum()) / first.getDiv()
		== static_cast<double>(second.getNum()) / second.getDiv();
}

bool operator!=(const Fraction& first, const Fraction& second)
{
	return !(first == second);
}

bool operator<(const Fraction& first, const Fraction& second)
{
	return static_cast<double>(first.getNum()) / first.getDiv()
		< static_cast<double>(second.getNum()) / second.getDiv();
}

bool operator>(const Fraction& first, const Fraction& second)
{
	return !(first < second) && (first != second);
}

bool operator<=(const Fraction& first, const Fraction& second)
{
	return !(first > second);
}

bool operator>=(const Fraction& first, const Fraction& second)
{
	return !(first < second);
}

Fraction operator+(const Fraction& first, const Fraction& second)
{
	if (first.f_div != second.f_div)
	{
		Fraction tmp(first.f_num * second.f_div + second.f_num * first.f_div, first.f_div * second.f_div);
		tmp.reduction();
		return tmp;
	}
	
	Fraction tmp(first.f_num + second.f_num, first.f_div);
	tmp.reduction();
	return tmp;
}

Fraction operator+(const Fraction& first, int second)
{
	return Fraction(first.f_num + second * first.f_div, first.f_div);
}

Fraction operator-(const Fraction& first, const Fraction& second)
{
	if (first.f_div != second.f_div)
	{
		Fraction tmp(first.f_num * second.f_div - second.f_num * first.f_div, first.f_div * second.f_div);
		tmp.reduction();
		return tmp;
	}

	Fraction tmp(first.f_num - second.f_num, first.f_div);
	tmp.reduction();
	return tmp;
}

Fraction operator-(int first, const Fraction& second)
{
	return Fraction(first * second.f_div + second.f_num, second.f_div);
}

Fraction operator*(const Fraction& first, const Fraction& second)
{
	Fraction tmp(first.f_num * second.f_num, first.f_div * second.f_div);
	tmp.reduction();
	return tmp;
}

Fraction operator/(const Fraction& first, const Fraction& second)
{
	Fraction tmp(first.f_num * second.f_div, first.f_div * second.f_num);
	tmp.reduction();
	return tmp;
}


int main(int argc, char const *argv[])
{
	Fraction f1(2, 3);
	Fraction f2(5, 2);

	(f1 + f2).print();
	(f1 + 2).print();
	(f1 - f2).print();
	(2 - f2).print();
	(f1 * f2).print();
	(f1 / f2).print();

	return 0;
}

