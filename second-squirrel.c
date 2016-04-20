// second-squirel

#include <stdlib.h>
#include <stdio.h>

void manyLines();
void printLine();

int main() {
	// Initial lines
	manyLines();
	// Actual line
	printf( "01 Well done! It's time to search for the golden nut\n" );
	printf( "02 It's hidden somewhere along these branches\n");
	printf( "03 You might need grep and a look at the man page\n");
	printf( "04 So you can easily search through all these branches\n");
	// Final lines
	manyLines();
}

void manyLines() {
	int r;
	r = rand() % 500;
	r += 1000;
	for( int i = 0; i < r; i++ ) {
		printLine();
	}
}

void printLine() {
	int r;
	// Number to print
	r = rand() % 100;
	while( r == 1 || r == 0) {
		r = rand() % 100;
	}
	// Print number
	printf( "%d ", r );
	// Line length
	r = rand() % 20;
	r += 20;
	// Print line
	for( int i = r; i > 0; i-- ) {
		r = rand() % 30;
		r += 97;
		if( r >= 123 ) {
			r = 32;
		}
		printf( "%c", r );
	}
	// Newline
	printf( "\n" );
}
