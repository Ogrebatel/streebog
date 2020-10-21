#include "TK26.h"

void inc504(char* a){
    int i;
    for(i = 0; i < 63; ++i){
        ++a[i];
        if (a[i] != 0) break;
    }
}

char* TK26(char* _R, unsigned t, char* K){
    unsigned h = 64, m = 64, s = 32;
    unsigned r = t % h, q = t / h;
    unsigned l = m - s - 1;
    // t = q * h + г
    char _C[64];
    char _U[63];
    memcpy(_U, K, s);
    memset(_U + s, 0, l);

    unsigned i;

    for(i = 0; i < q; ++i){
        inc504(_U);
        hash512(_C, _U, GOST_512, 63);
        memcpy(_R + i*64, _C, 64);
    }

    if (r != 0){
        inc504(_U);
        hash512(_C, _U, GOST_512, 63);
        memcpy(_R + i*64, _C, r);
    }
    return _R;
}