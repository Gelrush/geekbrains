#include <iostream>

class Car
{
protected:
	std::string c_company;
	std::string c_model;
public:
	Car(std::string company, std::string model)
		: c_company(company), c_model(model)
	{	
		std::cout << "Create 'Car' " << c_company << ' ' << c_model << std:: endl;
	}
	
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(std::string company, std::string model)
		: Car(company, model)
	{
		std::cout << "Create 'Passenger car' " << c_company << ' ' << c_model << std:: endl;
	}
	
};

class Bus : virtual public Car
{
public:
	Bus(std::string company, std::string model)
		: Car(company, model)
	{
		std::cout << "Create 'Bus' " << c_company << ' ' << c_model << std:: endl;
	}
	
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string company, std::string model)
		: PassengerCar(company, model), Bus(company, model), Car(company, model)
	{
		std::cout << "Create 'Minivan' " << c_company << ' ' << c_model << std:: endl;
	}
	
};



int main(int argc, char const *argv[])
{
	Car c1("Car-c", "car-m");
	puts("");
	PassengerCar c2("PassengerCar-c", "PassengerCar-m");
	puts("");
	Bus c3("Bus-c", "Bus-m");
	puts("");
	Minivan c4("Minivan-c", "Minivan-m");


	return 0;
}