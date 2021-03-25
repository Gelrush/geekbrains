#include <iostream>
#include <cmath>

const double PI{ 3.14 };

class Figure
{
public:
	virtual float area() const = 0;
	
};

class Parallelogram : public Figure
{
protected:
	float sideA{ 0 };
	float sideB{ 0 };
public:
	Parallelogram(float a, float b)
		: sideA(a), sideB(b)
	{
		if (a < 0 || b < 0)
			std::cerr << "Uncorrect options" << std::endl;	
	}

	float area() const override
	{
		return sideA * sideB;
	}	

};

class Circle : public Figure
{
private:
	float radius{ 0.0 };
public:
	Circle(float r)
		: radius(r)
	{
		if (r < 0)
			std::cerr << "Uncorrect options" << std::endl;
	}

	float area() const override
	{
		return PI * pow(radius, 2);
	}	
	
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(float a, float b)
		: Parallelogram(a, b)
	{	}
	
};

class Square : public Parallelogram
{
public:
	Square(float a, float b)
		: Parallelogram(a, b)
	{	}
	
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(float a, float b)
		: Parallelogram(a, b)
	{	}
	
};

int main(int argc, char const *argv[])
{
	Figure *f = new Parallelogram(3.5, 4.1);
	std::cout << "Parallelogram area = " << f->area() << std::endl;
	f = new Circle(4);
	std::cout << "Circle area = " << f->area() << std::endl;
	f = new Rectangle(3, 5);
	std::cout << "Rectangle area = " << f->area() << std::endl;
	f = new Square(4, 5);
	std::cout << "Square area = " << f->area() << std::endl;
	f = new Rhombus(2, 5);
	std::cout << "Rhombus area = " << f->area() << std::endl;
	// да тут везде остались висячие указатели

	return 0;
}

