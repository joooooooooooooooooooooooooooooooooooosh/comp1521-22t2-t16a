#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: first_line <file>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror(argv[1]);
        return 1;
    }

    int c;
    c = fgetc(f);
    while(c != EOF) {
        putchar(c);
        if (c == '\n') break;
        c = fgetc(f);
    }
}
