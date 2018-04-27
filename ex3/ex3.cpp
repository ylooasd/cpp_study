#include <iostream>
using namespace std;


class CMember {
	private:
	const char* name ;
	int num;
	int birth;

	public:
	CMember(const char* a, int b, int c) : name(a), num(b), birth(c) { }
	CMember(const char* a) : name(a), num(0), birth(0) { }
	CMember() : num(0), birth(0) { }
	void SetName(const char* a) { name = a; }
	void SetID(int a) { num = a; }
	void SetDOB(int a) { birth = a; }
	void Print() {
		cout << "Name : " << name << endl;
		if(num!=0)
			cout << "ID : " << num << endl;
		else
			cout << "ID : " << endl;
		if(birth!=0)
			cout << "DOB : " << birth << endl;
		else
			cout << "DOB : " << endl;
	}
	~CMember () { cout << name << " deleted!" << endl; }
};

int main(void) {
	char name[10] = {"Amy"};
	int DOB = 880101;

	CMember m1("Kim Seon-Suk");
	CMember m2("Max", 1, 931208);
	CMember m3;

	m1.Print();
	m2.Print();
	m3.SetName(name);
	m3.SetID(2);
	m3.SetDOB(DOB);
	m3.Print();

	return 0;
}
