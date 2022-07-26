#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUF_SIZ 1000

int main(int argc, char **argv) {
    char *home = getenv("HOME");
    if (home == NULL) {
        perror(home);
        return EXIT_FAILURE;
    }
    char *diary = "/.diary";

    size_t size = strlen(home) + strlen(diary) + 1;
    char *path = malloc(size);
    snprintf(path, size, "%s%s", home, diary);

    FILE *f = fopen(path, "r");
    if (f == NULL) {
        perror(path);
        return EXIT_FAILURE;
    }

    char buf[BUF_SIZ];
    size_t read;
    do {
        read = fread(buf, 1, BUF_SIZ, f);
        write(1, buf, read);
    } while (read == BUF_SIZ);

    return EXIT_SUCCESS;
}
