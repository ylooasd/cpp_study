#include <iostream>
using namespace std;
#include "shape.h"
#include "rect.h"
#include "circle.h"


ostream &operator<<(ostream &out, CShape &C) {
	C.Print();
	return out;
}

int main(void) {
	CCircle<double> Cir1(1, 1, 1.1), Cir2(2, 2, 2.2);
	CCircle<double> Cir3 = Cir1 + Cir2;
	CCircle<int> Cir4(1, 1, 1), Cir5(2, 2, 2);
	CCircle<int> Cir6 = Cir4 + Cir5;

	CRect<int> Rect(2, 2, 2, 2);
	CShape *pSpe;

	pSpe = &Cir3;
	cout << *pSpe;

	pSpe = &Rect;
	cout << *pSpe;

	pSpe = &Cir6;
	cout << *pSpe;

	return 0;
}
