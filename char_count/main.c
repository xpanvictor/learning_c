#include <stdio.h>

int main(){
	long nc; // long to store count
	
	nc = 0;
	
	while (getchar() != EOF)
		++nc;

	// at end of file, print count
	printf("%ld\n", nc);
}
