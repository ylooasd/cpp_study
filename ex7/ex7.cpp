#include <iostream>
using namespace std;

class CPointX {
protected:
	int x;

public:
	CPointX(int a) : x(a) {}
	CPointX() : x(0) {}
	virtual void Print() { cout << "CPointX" << endl;}
};

class CPointXY : virtual public CPointX {
protected:
	int y;

public:
	CPointXY(int a, int b) : CPointX(a), y(b) {}
	void Print() { cout << "CPointXY" << endl;}
};

class CPointXZ : virtual public CPointX {
protected:
	int z;

public:
	CPointXZ(int a, int c) : CPointX(a), z(c) {}
	void Print() { cout << "CPointXZ" << endl;}
};

class CPointXYZ : public CPointXY, public CPointXZ {
protected:
	int xyz;

public:
	CPointXYZ(int a, int b, int c) : CPointX(a), CPointXY(a, b), CPointXZ(a, c), xyz(a * b * c) {}
	void Print() {
		cout << "x: " << x << endl;
		CPointX::Print();
		CPointXY::Print();
		CPointXZ::Print();
		cout << "CPointXYZ" << endl;
	}
};

void AnyPrint(CPointX &target) {
	target.Print();
}

int main(void) {

	CPointX px(1);
	CPointXY pxy(1, 2);
	CPointXZ pxz(1, 3);
	CPointXYZ pxyz(1, 2, 3);

	AnyPrint(px);
	AnyPrint(pxy);
	AnyPrint(pxz);
	AnyPrint(pxyz);
}
