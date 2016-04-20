#include <stdio.h>
#include <string.h>
int mod(int x, int y) {
    if (x >= 0) {
        return x % y;
    }
    return mod(y + x, y);
}
void rot(char* s) {
    for (unsigned long i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (c != ' ' && c != '\n' && c != '-') {
            char newPos = ((c + 50) - 'a');
            char newC = mod(newPos, 26) + 'a';
            s[i] = newC;
        }
    }
}

int main() {
    char d1 = '1';
    char d2 = '0';
    char d3 = '0';
    char code[100];
    strcpy(code, "dgnnocp-hqtf\n");
    rot(code);
    printf("Hello, could I ask of you to find me a very special number in the library?\n"
           "I'll make it worth your while\n");
    printf("Have you found my number yet?\n");
    int c;
    char str[5];
    int index = 0;
    while ((c = getchar()) != EOF && c != '\n' && index < 5) {
        str[index] = c;
        index++;
    }
    if (str[0] == d1 && str[1] == d2 && str[2] == d3) {
        printf("Ah yes, the number I was looking for!\n"
                "Allow me to show my gratitude. Your final challenge code is\n"
              );
        printf("%s", code);
        printf("You should go to our king and present to him your challenge codes\n");
    }
    else {
        printf("Hmm, that's not exactly what I was looking for...\n");
    }
}
