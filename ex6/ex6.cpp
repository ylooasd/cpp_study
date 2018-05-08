#include <iostream>
#include <cstdio>
#define PI 3.14
using namespace std;

class CCircle {
protected:
	int x, y;
	double Radius;

public:
	CCircle(int x_, int y_, double Radius_) : x(x_), y(y_), Radius(Radius_) {}
	double GetArea() {return (PI * Radius * Radius);}
};

class CCyilnder : public CCircle {
private:
	int z;
	double Heigh;

public:
	CCyilnder(int x_, int y_, int z_, double Radius_, double Heigh_) : CCircle(x_, y_, Radius_), z(z_), Heigh(Heigh_) {}
	double GetArea() {return (PI * Radius * Radius * 2 + 2* PI * Radius * Heigh);}
	int &operator[] (int a) {
		if(a == 0) return x;
		else if(a == 1) return y;
		else if(a == 2) return z;
	}
	CCyilnder &operator++() { x++; y++; z++; return (*this);}
	friend ostream &operator<<(ostream &out, const CCyilnder P);
};

ostream &operator<<(ostream &out, const CCyilnder P) {
	printf("(%d, %d, %d, %.1lf, %.1lf)", P.x, P.y, P.z, P.Radius, P.Heigh);
	return out;
}

int main(void) {
	CCyilnder cyl(2, 2, 2, 2.0, 2.0);

	cout << cyl <<endl;
	cout << cyl.GetArea() << endl;
	cout << cyl.CCircle::GetArea() << endl;

	cyl[0] = cyl[1] = cyl[2] = 1;
	++(++cyl);
	cout << cyl[0] << cyl[1] << cyl[2] << endl;
}

