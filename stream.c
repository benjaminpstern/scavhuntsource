#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int mod(int x, int y) {
    if (x >= 0) {
        return x % y;
    }
    return mod(y + x, y);
}
int rot(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (c != ' ' && c != '\n' && c != '-') {
            char newPos = ((c - 50) - 'a');
            char newC = mod(newPos, 26) + 'a';
            s[i] = newC;
        }
    }
}
int main() {
    char message[1000];
    strcpy(message, "rfc mlc ufgaf wms qcci gq y aspgmsq-buypd\n"
            "ufm qcciq y iglb md ilmujcbec mljw wms ayl npmtgbc\n"
            "rcjj fgk ufyr fc lccbq rm ilmu ylb wms qfyjj dglb pcuypbq zcwmlb kcyqspc\n"
            "rfcpc gq y jgzpypw md qapmjjq\n"
            "rfc buypd gq glrcpcqrcb gl rfc lskzcp md jglcq gl rfc dgpqr dgdrccl qapmjjq yjnfyzcrgayjjw\n"
          );
    /*
    strcpy(message,"the one which you seek is a curious-dwarf\n"
        "who seeks a kind of knowledge only you can provide\n"
        "tell him what he needs to know and you shall find rewards beyond measure\n"
        "there is a library of scrolls\n"
        "the dwarf is interested in the number of lines in the first fifteen scrolls alphabetically\n");
        */
    int newline = '\n';
    srand(time(NULL));
    rot(message);
    printf("%s",message);
    while (1) {
        int c = (rand() % 50) + newline;
        putchar(c);
    }
    return 0;
}
