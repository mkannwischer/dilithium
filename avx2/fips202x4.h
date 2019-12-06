#ifndef DILITHIUM_FIPS202X4_H
#define DILITHIUM_FIPS202X4_H

#include <immintrin.h>
#include <stdint.h>

#include "params.h"

void DILITHIUM_shake128_absorb4x(
        __m256i *s,
        const uint8_t *m0,
        const uint8_t *m1,
        const uint8_t *m2,
        const uint8_t *m3,
        unsigned long long mlen);

void DILITHIUM_shake128_squeezeblocks4x(
        uint8_t *h0,
        uint8_t *h1,
        uint8_t *h2,
        uint8_t *h3,
        unsigned long nblocks,
        __m256i *s);

void DILITHIUM_shake256_absorb4x(
        __m256i *s,
        const uint8_t *m0,
        const uint8_t *m1,
        const uint8_t *m2,
        const uint8_t *m3,
        unsigned long long mlen);

void DILITHIUM_shake256_squeezeblocks4x(
        uint8_t *h0,
        uint8_t *h1,
        uint8_t *h2,
        uint8_t *h3,
        unsigned long nblocks,
        __m256i *s);

void DILITHIUM_shake128_4x(
        uint8_t *h0,
        uint8_t *h1,
        uint8_t *h2,
        uint8_t *h3,
        unsigned long long hlen,
        const uint8_t *m0,
        const uint8_t *m1,
        const uint8_t *m2,
        const uint8_t *m3,
        unsigned long long mlen);

void DILITHIUM_shake256_4x(
        uint8_t *h0,
        uint8_t *h1,
        uint8_t *h2,
        uint8_t *h3,
        unsigned long long hlen,
        const uint8_t *m0,
        const uint8_t *m1,
        const uint8_t *m2,
        const uint8_t *m3,
        unsigned long long mlen);

#endif
