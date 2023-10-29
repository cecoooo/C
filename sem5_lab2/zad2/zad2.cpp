#include <iostream>
using namespace std;

class Truck;

class Car
{
	int speed;
	int passengers;
public:
	Car(int p, int s)
	{
		this->passengers = p;
		this->speed = s;
	}
	friend int sp_greater(Car car, Truck truck);
	int passangers_max(Truck truck);
	friend void time_to_travel(double km, Car c, Truck t);
};

class Truck
{
	int weight;
	int speed;
public:
	Truck(int w, int s)
	{
		this->weight = w;
		this->speed = s;
	}
	friend int sp_greater(Car, Truck);
	friend int Car::passangers_max(Truck);
	friend void time_to_travel(double km, Car c, Truck t);
};

int Car::passangers_max(Truck truck)
{
	return truck.weight - passengers;
}

int sp_greater(Car car, Truck truck) 
{
	return car.speed - truck.speed;
}

void time_to_travel(double km, Car c, Truck t)
{
	cout << "FOR CAR: " << km / c.speed << " HOURS" << '\n';
	cout << "FOR TRUCK: " << km / t.speed << " HOURS" << '\n';
}

int main() 
{
	Car c(4, 120);
	Truck t(40, 100);
	cout << sp_greater(c, t) << '\n';
	cout << c.passangers_max(t) << '\n';
	time_to_travel(321, c, t);
}