#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv) {
    int32_t aaaa = -30000 - 30000;
    printf("%d\n", aaaa);
    return EXIT_SUCCESS;
}

// 1 -> 0000 0001
// 100 = 64 + 32 + 4 -> 0110 0100
// 1000 = 512 + 256 + 128 + 64 + 32 + 8 -> 0000 0011 1110 1000
//
// two's complement: flip bits and add one
// 5 = 0000 0000 0000 0101
//     1111 1111 1111 1010
// -5= 1111 1111 1111 1011
//     0000 0000 0000 0100
// 5 = 0000 0000 0000 0101
//
// -5 + 10
// -5= 1111 1111 1111 1011
// 10= 0000 0000 0000 1010
//  5= 0000 0000 0000 0101
