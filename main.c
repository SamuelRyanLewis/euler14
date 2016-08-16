#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * Project Euler Problem 14
 * Longest Collatz Sequence
 * Which number, under 1,000,000, produces the longest chain?
 * EVEN: n/2
 * ODD: 3n+1
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 */

/**
 * The struct collatzData contains the data about our
 * longest chain collatzData sequence starting number
 */
struct collatzData {
	int number;
	int length;
};

/**
 * sequenceLength takes a number and returns the
 * length of its collatz sequence as an integer
 */
long sequenceLength(long number) {
	long length = 1;
	while(number > 1) {
		if(number % 2 == 1) { //odd case
			number = (3 * number) + 1;
		} else {
			number = number / 2;
		}
		length++;
	}
	return length;
}


/**
 * The main function contains the general logic for the program.
 * 
 *
 */
int main(void) {
	clock_t t;
	t = clock();	

	struct collatzData collatz;
	collatz.number = 1; //initialize starting at 1
	collatz.length = 1;
	int currLength = 0;
	for(int x = 2; x < 1000000; x++) {
		currLength = sequenceLength(x);
		if(currLength == -1) {
			printf("Error\n");
			exit(1);
		}
		if(currLength > collatz.length) {
			collatz.number = x;
			collatz.length = currLength;
		}
	}
	t = clock() - t;
	double timeTaken = ((double)t)/CLOCKS_PER_SEC;
	printf("Starting Number: %d\n", collatz.number);
	printf("Sequence Length: %d\n", collatz.length);
	printf("Time taken: %f seconds\n", timeTaken);

}

