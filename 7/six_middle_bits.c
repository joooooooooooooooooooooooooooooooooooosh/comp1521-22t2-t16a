#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t six_middle_bits(uint16_t num);

int main(int argc, char **argv) {
    printf("%x\n", six_middle_bits(0x53b0));
    return EXIT_SUCCESS;
}


//                |     |      
// input: 0b0101 0011 1011 0000 = 0x53b0
// shift: 0b0000 0010 1001 1101
// mask:  0b0000 0000 0011 1111 = 0x3f
// output 0b0000 0000 0001 1101 = 0x1d
uint16_t six_middle_bits(uint16_t num) {
    uint32_t result = num >> 5;
    return result & 0x3f;
}
