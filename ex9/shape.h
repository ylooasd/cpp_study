#ifndef _MY_SHAPE_
#define _MY_SHAPE_

class CShape {
protected:
	int x, y;

public:
	CShape(int a, int b) : x(a), y(b) {}
	void Move(int a, int b) { x += a; y +=b; }
	virtual void Print() = 0;
};

#endif
