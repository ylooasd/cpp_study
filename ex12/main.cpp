#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class CPoint {
private:
	int x, y;
public:
	CPoint(int a = 0, int b = 0) : x(a), y(b) {}
	friend void printcpoint(CPoint &po);
	bool operator==(const CPoint &P) {
		if ( x == P.x && y == P.y)
			return true;
		else
			return false;
	}
	bool operator<(CPoint P) {
		if ( x + y < P.x + P.y)
			return true;
		else
			return false;
	}
};

ostream &operator<<(ostream &out, CPoint &Po) {
	printcpoint(Po);
	return out;
}

void printcpoint(CPoint &po) {
	cout << "(" << po.x << ", " << po.y << ") ";
}

int main(void) {

	vector<CPoint> poV(5), poV2(5), poV3(10);
	vector<CPoint>::iterator iter, iter2;
	int i;
	CPoint po2find;

	for (iter = poV.begin(), i = 0 ; iter != poV.end() ; iter++, i++)
		(*iter) = CPoint(i + 1, i + 2);

	for (iter = poV2.begin(), i = 0 ; iter != poV2.end() ; iter++, i++)
		(*iter) = CPoint(i, i);

	cout << "poV: "; for_each(poV.begin(), poV.end(), printcpoint);
	cout << endl;
	cout << "poV2: "; for_each(poV2.begin(), poV2.end(), printcpoint);
	cout << endl;
	cout << "poV3: "; for_each(poV3.begin(), poV3.end(), printcpoint);
	cout << endl;

	po2find = CPoint(3, 4);
	iter = find(poV.begin(), poV.end(), po2find);
	if (iter != poV.end())
		cout << "poV에 " << po2find << "는 존재합니다." << endl;
	else
		cout << "poV에 " << po2find << "는 존재하지 않습니다" << endl;

	iter = find(poV3.begin(), poV3.end(), CPoint(3, 4));
	if (iter != poV3.end())
		cout << "poV3에 " << po2find << "는 존재합니다." << endl;
	else
		cout << "poV3에 " << po2find << "는 존재하지 않습니다" << endl;
	
	merge(poV.begin(), poV.end(), poV2.begin(), poV2.end(), poV3.begin());
	
	cout << "poV3L "; for_each(poV3.begin(), poV3.end(), printcpoint);
	cout << endl;

	iter = find(poV3.begin(), poV3.end(), CPoint(3, 4));

	for (i = 0 ; ; i++) {
		iter2 = find(poV3.begin(), poV3.end(), poV3[i]);
		if (iter == iter2)
			break;
	}

	cout << (*iter) << "는 poV3의 " << i << "번째 원소입니다." << endl;

	rotate(poV3.begin(), poV3.begin()+2, poV3.end());
	cout << "Rotate : "; for_each(poV3.begin(), poV3.end(), printcpoint);
	cout << endl;

	return 0;
}
