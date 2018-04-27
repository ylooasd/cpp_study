#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void comp(char* a, char* b,int ssize) {
	int n = 0;
	int i=0,j=0;
	for(int i = 0; a[i] != 0 ; i++) {
		n=0;
		if(a[i] == b[i])
			for(j = 1 ; n==0 && j<ssize; j++) {
				if(a[i+j] == b[j]) {
					n = 0;
				}
				else
					n = 1; 
			}
		if(j == ssize) {
			if (n == 0) {
				printf("포함\n");
				break;
				}
			else {
				printf("미포함\n");
				break;
			}
		}
	}

}

int main(int argc, char* argv[]) {
	int tn1,tn2;
	tn1 = strlen(argv[1]);
	tn2 = strlen(argv[2]);
	if(tn1 <= 1 || tn2 <= 1)
		exit(1);
	if(tn1 >= tn2)
		comp(argv[1],argv[2],tn2);
	else
		comp(argv[2],argv[1],tn1);

	return 0;
}
