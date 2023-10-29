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
};

#include "Car.h"