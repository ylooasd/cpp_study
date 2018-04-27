#include <iostream>
#define NUM 4
using namespace std;

class CComplex {
private:
	float re, im;

public:
	CComplex() : re(0), im(0) { }
	CComplex(float a, float b) : re(a), im(b) { }
	void set(float a, float b) { re = a, im = b; }
	CComplex operator+(const CComplex &P0) { return CComplex(re + P0.re, im + P0.im); }
	CComplex operator-(const CComplex &P0) { re = -re; im = -im; return (*this); }
	CComplex operator*(const CComplex &P0) { return CComplex(re * P0.re - im * P0.im, re * P0.im + im * P0.re); }
	void print() {
		if (re == 0) {
			if (im > 0)
				cout << "+ " << im << "i" << endl;
			else if (im == 0)
				cout << "0" << endl;
			else if (im < 0)
				cout << " - " << -im << "i" << endl;
		}
		else {
			if (im > 0)
				cout << re << " + " << im << "i" << endl;
			else if (im == 0)
				cout << re << endl;
			else if (im < 0)
				cout << re << " - " << -im << "i" << endl;
		}
	}
};

int main(void) {
	CComplex *zlist = new CComplex[NUM];
	float real[] = { 1.1, 3.3, 5.6, -1.3};
	float imag[] = { 1.3, -5.6, 3.3, -1.1};

	for(int i = 0 ; i < NUM ; i++) {
		zlist[i].set(real[i], imag[i]);
		zlist[i].print();
	}

	CComplex zt = zlist[0] + zlist[1] + CComplex(1.1, 1.1);
	zt.print();
	zt.set(1, 3);
	(zt * CComplex(2, 4)).print();
	(zlist[0] - zlist[1]).print();

	delete [] zlist;
}
