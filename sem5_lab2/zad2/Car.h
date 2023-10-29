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
};

int Car::passangers_max(Truck truck) 
{
	return truck.weight - passengers;
}