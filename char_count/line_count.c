#include <stdio.h>

int main(){
	double nl;
	int c;

	nl = 0;
	
	while ((c = getchar()) != EOF){
		if (c == '\n')
			++nl;
	}

	printf("%lg \n", nl);
}
