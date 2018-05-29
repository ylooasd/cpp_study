#include <iostream>
using namespace std;
#include "shape.h"
#include "circle.h"
#include <vector>
#include <list>

ostream &operator<<(ostream &out, CShape &C) {
	C.Print();
	return out;
}

int main(void) {

	int i;
	vector<CCircle<double> > cirv;
	vector<CCircle<double> >::iterator viter, viterb;
	for (i = 0 ; i < 5 ; i++ )
		cirv.push_back(CCircle<double>(1, 1, 1.1 + i));

	viter = cirv.begin();
	for (i = 0 ; i < 5 ; i++) {
		cout << *viter;
		viter++;
	}

	viter = viterb = cirv.begin();
	viter++;

	for (i = 0 ; i < 5 ; i++) {
		if (*viterb < *viter) {
			*viterb = *viter;
		}
		viter++;
	}

	viter = cirv.begin();
	cout << *viter;

	return 0;
}
