#include <stdio.h>

int main(){
	int c;

	// keep printing c and getting new until end of file indicator
	while ((c = getchar()) != EOF){
		putchar(c);
	}
	printf("%d", EOF);
}
