#include <stdio.h>

int main(){
	int c;

	c = getchar();
	// keep printing c and getting new until end of file indicator
	while (c != EOF){
		putchar(c);
		c = getchar();
	}
}
