#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Word;
Word reverseBits(Word w) {
    Word ret = 0;
    int num_bits = sizeof(Word) * 8;
    for (int i = 0; i < num_bits; i++) {
        // 1 << 31 = 1000 0000 000...
        int mask = 1 << (num_bits - i - 1);
        // check if the bit in w is set
        //
        // CAREFUL:
        // if (w & mask != 0) { 
        // if (w & (mask != 0)) { 
        // if (w & 1) { 
        if ((w & mask) != 0) { 
            // set i'th bit in ret to 1
            ret = ret | (1 << i);
        }
    }

    return ret;
}

int main(int argc, char **argv) {
    Word w = 0x01234567;
    printf("%X\n", reverseBits(w));
    return EXIT_SUCCESS;
}

