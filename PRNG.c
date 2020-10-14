#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "streebog.c"

#define bool char
#define GOST_256 0
#define GOST_512 1


//---------------PRNG_BLOCK-----------------
void inc504(char* a){
    int i;
    for(i = 0; i < 63; ++i){
        ++a[i];
        if (a[i] != 0) break;
    }
}

char* PRNG(unsigned t, char* K){
    t*=8;
    unsigned h = 512, m = 512, s = 256;
    unsigned r = t % h, q = t / h;
    unsigned l = m - s - 8; // = 248
    // t = q * h + г
    char* _C = (char*)malloc(64);
    char* _U = (char*)malloc(63);
    char* _R = (char*)malloc(t/8);
    memcpy(_U, K, s/8);
    memset(_U + s/8, 0, l/8);

    unsigned i;

    streeb_context ctx;

    for(i = 0; i < q; ++i){
        inc504(_U);
        streeb_context_init(&ctx, _U, GOST_512, 63);
        first_stage(&ctx);
        second_stage(&ctx);
        third_stage(&ctx);
        memset(_C, 0,64);
        memcpy(_C, ctx.h.b, 64);
        memcpy(_R + i*64, _C, 64);
    }

    if (r != 0){
        inc504(_R);
        streeb_context_init(&ctx, _R, GOST_512, 63);
        first_stage(&ctx);
        second_stage(&ctx);
        third_stage(&ctx);
        memset(_C, 0,64);
        memcpy(_C, ctx.h.b, 64);

        memcpy(_R + i*64, _C, r / 8);
    }
    free(_C);
    free(_U);
    return _R;
}
//----------------------------------------------
int main() {
    int i;
    char a[32] = "asdfghjkloiuytrewqaszxcdfvbghnmj";
    char* rez = PRNG(108, a);
    for(i = 107; i >= 0; --i){
        printf("%02x", (uint8_t)rez[i]);
    }

    return 0;
}

