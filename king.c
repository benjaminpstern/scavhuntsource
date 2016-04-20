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
            char newPos = ((c - 50) - 'a');
            char newC = mod(newPos, 26) + 'a';
            s[i] = newC;
        }
    }
}

int main() {
    printf("Please enter your challenge codes:\n");
    char* code1 = "fyqfkyn";
    char* code2 = "zglypw-qcypaf";
    char* code3 = "zcjjkyl-dmpb";
    char code1Space[100];
    char code2Space[100];
    char code3Space[100];
    strcpy(code1Space, code1);
    strcpy(code2Space, code2);
    strcpy(code3Space, code3);
    rot(code1Space);
    rot(code2Space);
    rot(code3Space);
    // printf("%s %s %s\n", code1Space, code2Space, code3Space);
    char input[3][100];
    int inputNum = 0;
    int index = 0;
    int c;
    while (inputNum < 3 && (c = getchar()) != EOF) {
        if (c == '\n') {
            input[inputNum][index] = 0;
            inputNum++;
            index = 0;
        }
        else {
            input[inputNum][index] = c;
            index++;
            if (index >= 100) {
                index = 0;
                inputNum++;
            }
        }
    }
    // printf("%s %s %s\n", input[0], input[1], input[2]);
    int isCorrect = (!strcmp(code1Space, input[0])) &&
        (!strcmp(code2Space, input[1])) &&
        (!strcmp(code3Space, input[2]));
    if (isCorrect) {
        printf("Congratulations, you have solved completed the scavenger hunt challenge\n");
    }
    else {
        printf("Your codes are not correct\n");
    }
    return 0;
}
