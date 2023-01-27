#include <stdio.h>

/* function to print fahrenheit celsius table */
int main(){
	float celsius;
	int fahr, lower, upper, step;
	
	#define LOWER 0 /* the lower limit of the temperatures */
	#define UPPER 300 /* the upper limit of the temperatures */
	#define STEP 20 /* the intervals for the temp */

	/* for loop going from lower to upper in steps */
	
	for (fahr = LOWER; fahr <= UPPER; fahr += STEP){
		celsius = (5.0 / 9.0) * (fahr - 32);
		printf("%3d %6.1f\n", fahr, celsius);	
	}
}
