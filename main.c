#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "streebog.h"
#include "TK26.h"

#define bool char
#define GOST_512 1
#define GOST_256 0

int main() {
    int i;
    char a[32] = "asdfghjkloiuytrewqaszxcdfvbghnmj";
    char rez[108];
    TK26(rez, 108, a);
    for(i = 107; i >= 0; --i){
        printf("%02x", (uint8_t)rez[i]);
    }
//    char test[63] = {"012345678901234567890123456789012345678901234567890123456789012"};
//    char rez[64];
//    char test[72] = {0xd1, 0xe5, 0x20, 0xe2, 0xe5, 0xf2, 0xf0,
//                     0xe8, 0x2c, 0x20, 0xd1, 0xf2, 0xf0, 0xe8,
//                     0xe1, 0xee, 0xe6, 0xe8, 0x20, 0xe2, 0xed,
//                     0xf3, 0xf6, 0xe8, 0x2c, 0x20, 0xe2, 0xe5,
//                     0xfe, 0xf2, 0xfa, 0x20, 0xf1, 0x20, 0xec,
//                     0xee, 0xf0, 0xff, 0x20, 0xf1, 0xf2, 0xf0,
//                     0xe5, 0xeb, 0xe0, 0xec, 0xe8, 0x20, 0xed,
//                     0xe0, 0x20, 0xf5, 0xf0, 0xe0, 0xe1, 0xf0,
//                     0xfb, 0xff, 0x20, 0xef, 0xeb, 0xfa, 0xea,
//                     0xfb, 0x20, 0xc8, 0xe3, 0xee, 0xf0, 0xe5,
//                     0xe2, 0xfb};

//     uint512_t rez;
//     hash512(rez.b, test, GOST_512, 63);
//     print_512(rez);

    return 0;
}

