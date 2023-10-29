#pragma once
class Rectangular
{
private:
	int a;
	int b;
public:
	Rectangular(int a, int b) {
		this->a = a;
		this->b = b;
	};
	
	int face() {
		return a * b;
	};
	int face(int* p) {
		int pp = 2 * (this->a + this->b);
		*p = pp;
		return this->a * this->b;
	};
};

