#include <stdio.h>

/* function to print fahrenheit celsius table */
int main(){
	float celsius;
	int fahr, lower, upper, step;
	
	lower = 0;
	upper = 300;

	step = 20;

	/* for loop going from lower to upper in steps */
	
	for (fahr = lower; fahr <= upper; fahr += step){
		celsius = (5.0 / 9.0) * (fahr - 32);
		printf("%3d %6.1f\n", fahr, celsius);	
	}
}
