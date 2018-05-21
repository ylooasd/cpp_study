//rect.h
#ifndef _MY_RECT_
#define _MY_RECT_
#include "shape.h"
class CRect : public CShape {
private:
	int Garo, Sero;

public:
	CRect(int a, int b, int g, int s) : CShape(a, b), Garo(g), Sero(s) {}
	double GetArea();
	void Print();
};
#endif
