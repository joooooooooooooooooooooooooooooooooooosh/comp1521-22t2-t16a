#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define READING   0x01 // 0000 0001
#define WRITING   0x02 // 0000 0010
#define AS_BYTES  0x04 // 0000 0100
#define AS_BLOCKS 0x08 // 0000 1000
#define LOCKED    0x10 // 0001 0000

int main(int argc, char **argv) {
    uint8_t device = 0;
    // mark the device as locked for reading bytes
    // target: 0b0001 0101 or 0x15
    device = READING;
    device = device | AS_BYTES;
    device = device | LOCKED;
    printf("0x%x\n", device);

    // mark the device as locked for writing blocks
    // target: 0b0001 1010 or 0x1A
    device = AS_BLOCKS;
    device = device | LOCKED;
    device = device | WRITING;
    printf("0x%X\n", device);

    // remove the lock on a device, leaving other flags unchanged
    // target: 0b0000 1010 or 0x0A
    // current device: 0001 1010
    //        ~locked: 1110 1111
    //                 0000 1010
    device = device & (~LOCKED);
    printf("0x%02X\n", device);

    // swap a device between reading and writing, leaving other flags unchanged 
    // current device: 0000 1010
    // R | W         : 0000 0011
    // target:         0000 1001 or 0x09
    //
    // alternate device: 0000 1001
    // R | W           : 0000 0011
    // target:           0000 1010
    device = device ^ (READING | WRITING);
    printf("0x%02X\n", device);

    return EXIT_SUCCESS;
}

