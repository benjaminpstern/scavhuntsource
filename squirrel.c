#include <stdio.h>
#include <stdlib.h>

void encrypt(char input[], unsigned int offset) {
	for (int i = 0; input[i] != '\0'; i++) {
		input[i] = input[i] + offset;
		putchar(input[i]);
    }
    putchar('\n');
}

int main() {
	char message[] = "You think it's hard to tell what I'm saying?";
	char message2[] = "Go talk to the other squirrel,"; 
	char message3[] = "it'll take some work to sort out what he's saying";
	encrypt(message, 2);
	encrypt(message2, 2);
	encrypt(message3, 2);
}
