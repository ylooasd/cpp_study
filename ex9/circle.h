#ifndef _MY_CIRCLE_
#define _MY_CIRCLE_
#include "shape.h"

template <typename T>
class CCircle : public CShape {
private:
	T Radius;

public:
	CCircle(int a, int b, T r) : CShape(a, b), Radius(r) {}
	double GetArea() { return ( 3.14 * Radius * Radius); }
	void Print() { cout << "Circle's area : " << GetArea() << endl; }
	CCircle operator+(const CCircle<T> &C) {
		return CCircle(x + C.x, y + C.y, Radius + C.Radius);
	}
};

#endif
