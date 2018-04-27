#include <iostream>
#include <cstring>
#define NMEM 5
using namespace std;


class CMember {
private :
	const char* name;
	int num;
	int birth;

public :
	CMember(const char* a, int b = -1, int c = -1) : num(b), birth(c) {
		int len = strlen(a);
		name = new char[len + 1];
		name = a;
	}
	CMember() : name(NULL), num(-1), birth(-1) {
		name = new char[10000];
	}
	CMember *SetName(const char* a) { name = a; return this; }
	CMember *SetID(int b) { num = b ; return this; } 
	CMember *SetDOB(int c) { birth = c; return this; }
	void Print() {
		cout << "Name : " << name << endl;
		if (num != -1)
			cout << "ID : " << num << endl;
		else
			cout << "ID : " << endl;
		if(birth != -1)
			cout << "DOB : " << birth << endl;
		else
			cout << "DOB : " << endl;
	}
	~CMember() { cout << name << " deleted!" << endl; }
};

int main(void) {
	char names[5][10] = {"Amy", "Bob", "Charles", "David", "Liz"};
	int DOBs[5] = { 880101, 890101, 910101, 920103, 880102};

	CMember m1("Kim Seon-Suk");
	CMember m2("Max", 1, 931208);
	CMember *memlist = new CMember[5];

	m1.Print();

	m2.Print();

	for(int i = 0 ; i < NMEM ; i++) {
		(memlist + i)->SetName(&names[i][0])->SetID(i+2);
		(memlist + i)->SetDOB(DOBs[i])->Print();
	}

	delete [] memlist;

	return 0;
}
