#ifndef POLY_H
#define POLY_H

#include <stdint.h>
#include <immintrin.h>

#include "alignment.h"
#include "params.h"

typedef union {
    uint32_t coeffs[N];
    __m256i coeffs_x8[N/8];
} poly;

void DILITHIUM_poly_reduce(poly *a);
void DILITHIUM_poly_csubq(poly *a);
void DILITHIUM_poly_freeze(poly *a);

void DILITHIUM_poly_add(poly *c, const poly *a, const poly *b);
void DILITHIUM_poly_sub(poly *c, const poly *a, const poly *b);
void DILITHIUM_poly_shiftl(poly *a);

void DILITHIUM_poly_ntt(poly *a);
void DILITHIUM_poly_invntt_montgomery(poly *a);
void DILITHIUM_poly_pointwise_invmontgomery(poly *c, const poly *a, const poly *b);

void DILITHIUM_poly_power2round(poly *a1, poly *a0, const poly *a);
void DILITHIUM_poly_decompose(poly *a1, poly *a0, const poly *a);
unsigned int DILITHIUM_poly_make_hint(poly *h, const poly *a0, const poly *a1);
void DILITHIUM_poly_use_hint(poly *a, const poly *b, const poly *h);

int  DILITHIUM_poly_chknorm(const poly *a, uint32_t B);
void DILITHIUM_poly_uniform(poly *a,
                            const uint8_t *seed,
                            uint16_t nonce);
void DILITHIUM_poly_uniform_4x(poly *a0,
                               poly *a1,
                               poly *a2,
                               poly *a3,
                               const uint8_t *seed,
                               uint16_t nonce0,
                               uint16_t nonce1,
                               uint16_t nonce2,
                               uint16_t nonce3);
void DILITHIUM_poly_uniform_eta(poly *a,
                                const uint8_t *seed,
                                uint16_t nonce);
void DILITHIUM_poly_uniform_eta_4x(poly *a0,
                                   poly *a1,
                                   poly *a2,
                                   poly *a3,
                                   const uint8_t *seed,
                                   uint16_t nonce0,
                                   uint16_t nonce1,
                                   uint16_t nonce2,
                                   uint16_t nonce3);
void DILITHIUM_poly_uniform_gamma1m1(poly *a,
                                     const uint8_t *seed,
                                     uint16_t nonce);
void DILITHIUM_poly_uniform_gamma1m1_4x(poly *a0,
                                        poly *a1,
                                        poly *a2,
                                        poly *a3,
                                        const uint8_t *seed,
                                        uint16_t nonce0,
                                        uint16_t nonce1,
                                        uint16_t nonce2,
                                        uint16_t nonce3);

void DILITHIUM_polyeta_pack(uint8_t *r, const poly *a);
void DILITHIUM_polyeta_unpack(poly *r, const uint8_t *a);

void DILITHIUM_polyt1_pack(uint8_t *r, const poly *a);
void DILITHIUM_polyt1_unpack(poly *r, const uint8_t *a);

void DILITHIUM_polyt0_pack(uint8_t *r, const poly *a);
void DILITHIUM_polyt0_unpack(poly *r, const uint8_t *a);

void DILITHIUM_polyz_pack(uint8_t *r, const poly *a);
void DILITHIUM_polyz_unpack(poly *r, const uint8_t *a);

void DILITHIUM_polyw1_pack(uint8_t *r, const poly *a);
#endif
