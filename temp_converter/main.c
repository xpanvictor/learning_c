#include <stdio.h>

/* function to print fahrenheit celsius table */
int main(){
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;

	step = 20;

	fahr = lower;
	/* while loop going from lower to upper in steps */
	
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
