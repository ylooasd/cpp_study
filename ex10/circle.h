#ifndef _MY_CIRCLE_
#define _MY_CIRCLE_
#include "shape.h"

template <typename T>
class CCircle : public CShape {
private:
	T Radius;

public:
	CCircle(int a, int b, T r) : CShape(a, b), Radius(r) {}
	double GetArea() { return (3.14 * Radius * Radius); }
	void Print() { cout << "Area:" << GetArea() << endl; }
	bool operator<(CCircle<T> &A) { if ( Radius < A.Radius) return true; else return false; }
	bool operator>(CCircle<T> &A) { if ( Radius > A.Radius) return true; else return false; }
};

#endif
