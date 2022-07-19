#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv) {
    FILE *f = fopen("f", "r");
    if (f == NULL) {
        perror("opening f");
    }

    return EXIT_SUCCESS;
}

