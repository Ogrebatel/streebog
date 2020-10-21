#ifndef STREEBOG_STREEBOG_H
#define STREEBOG_STREEBOG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define QW_SIZE 8
#define DW_SIZE 16
#define W_SIZE 32
#define B_SIZE 64
#define bool char
#define GOST_256 0
#define GOST_512 1

union uint512_t{
    uint64_t qw[QW_SIZE];
    uint32_t dw[DW_SIZE];
    uint16_t w[W_SIZE];
    uint8_t b[B_SIZE];
} typedef uint512_t;


union uint256_t{
    uint64_t qw[4];
    uint32_t dw[8];
    uint16_t w[16];
    uint8_t b[32];
} typedef uint256_t;

struct streeb_context{
    uint512_t h;
    uint512_t m;
    uint512_t N;
    uint512_t sum;
    char* M;
    uint512_t p_512;
    uint64_t size;
    bool type;
} typedef streeb_context;



void print_512 (uint512_t a);

void hash512(char* rez, char* M, bool type, unsigned size);

void streeb_context_init(streeb_context* ctx, char* M, bool type, unsigned size);
void first_stage(streeb_context* ctx);
void second_stage(streeb_context* ctx);
void third_stage(streeb_context* ctx);

#endif //STREEBOG_STREEBOG_H
