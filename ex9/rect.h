#ifndef _MY_RECT_
#define _MY_RECT_

template <typename T>
class CRect : public CShape {
private:
	T Garo, Sero;

public:
	CRect(int a, int b, T g, T s) : CShape(a, b), Garo(g), Sero(s) {}
	T GetArea() { return (Garo * Sero); }
	void Print() { cout << "Rect's area : " << GetArea() << endl; }

};

#endif
