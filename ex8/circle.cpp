//circle.cpp
#include <iostream>
#include "circle.h"
using namespace std;

double CCircle::GetArea() { return ( 3.14 * Radius * Radius); }
void CCircle::Print() { cout << "원의 면적 : " << GetArea() << endl; }
