#include <iostream>
#include <cstring>
using namespace std;

class CMember {
private:
	int iID;
	int iDOB;
	char *pName;
	static int count;

public:
	CMember() { iID = 0, iDOB = 0; count++; }

	CMember(const CMember &P0) {
		iID = P0.iID;
		iDOB = P0.iDOB;
		int len = strlen(P0.pName);
		pName = new char[len + 1];
		strcpy(pName, P0.pName);
		count++;
	}

	void SetName(char* a) {
		int len = strlen(a);
		pName = new char[len+1];
		strcpy(pName, a);
	}
	void SetID(int b) { iID = b; } 
	void SetDOB(int c) { iDOB = c; }

	friend void PrintInfo(CMember mem);
	friend CMember *GetMember(CMember *list, int index);

	static int GetCount() { return count; }

	~CMember() { count--; }
};

int CMember::count = 0;

void PrintInfo(CMember mem) {
	cout << "Name : " << mem.pName << endl;
	cout << "ID : " << mem.iID << endl;
	cout << "DOB : " << mem.iDOB << endl;
}

CMember *GetMember(CMember *list, int index) { return (list + index); }

int main(void) {

	CMember *memlist = new CMember[5];
	char names[5][10] = { "Amy", "Bob", "Charles", "David", "Liz"};
	int DOBs[5] = { 880101, 890101, 910101, 920103, 880102};

	for(int i = 0 ; i < 5 ; i++) {
		GetMember(memlist, i) -> SetName(names[i]);
		GetMember(memlist, i) -> SetID(i+1);
		GetMember(memlist, i) -> SetDOB(DOBs[i]);
	}

	for(int i = 0 ; i < 5 ; i++)
		PrintInfo(*(memlist + i));

	CMember orphmem1(*memlist), orphmem2(*(memlist + 2));
	PrintInfo(orphmem1);
	PrintInfo(orphmem2);

	cout << CMember::GetCount() << endl;

	delete [] memlist ;
	
	cout << CMember::GetCount() << endl;

}
