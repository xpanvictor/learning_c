#include <stdio.h>

int main(){
	double nc; // long to store count
	
	nc = 0;
	
	for (nc = 0; getchar() != EOF; ++nc);
	// at end of file, print count
	printf("%.0f\n", nc);
}
