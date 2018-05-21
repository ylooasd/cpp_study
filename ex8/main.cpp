//main.cpp
#include <iostream>
#include "shape.h"
#include "rect.h"
#include "circle.h"
using namespace std;

ostream &operator<<(ostream &out, CShape& C) {
	C.Print();
	return out;
}

int main(void) {
	
	CCircle Cir(1, 1, 1);
	CRect Rect(2, 2, 2, 2);
	CShape *pSpe;

	pSpe = &Cir;
	cout << *pSpe;

	pSpe = &Rect;
	cout << *pSpe;

	return 0;
}
