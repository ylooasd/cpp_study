//rect.cpp
#include <iostream>
#include "rect.h"
using namespace std;

double CRect::GetArea() { return ( Garo * Sero); }
void CRect::Print() { cout << "사각형 면적 : " << GetArea() << endl; }
