#include <iostream>
using namespace std;

int &Array(int *avry, int index) {
	return avry[index-1];
}

void arrayswap(int *a, int *b, int index) {
	int tmp;
	for(int i = 0 ; i< index ; i++) {
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
}

void SumMul(int *array, int num, int &sm, int &ml) {
	sm = 0, ml = 1;
	for(int i = 0 ; i < num ; i++) {
		sm = sm + array[i];
		ml = ml * array[i];
	}
}

int main(void) {
	int ary[5],ary4[5];
	int sum, mul;
	for(int i = 1 ; i < 6 ; i++) {
		Array(ary,i) = i * i;
	}
	
	arrayswap(ary,ary4,5);
	SumMul(ary4,5,sum,mul);
	
	cout<<"sum = "<<sum;
	cout<<", mul = "<<mul<<endl;
}

			
