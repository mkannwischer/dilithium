#ifndef DILITHIUM_PACKING_H
#define DILITHIUM_PACKING_H

#include "api.h"
#include "params.h"
#include "polyvec.h"

void DILITHIUM_pack_pk(
        uint8_t pk[DILITHIUM_CRYPTO_PUBLICKEYBYTES],
        const uint8_t rho[SEEDBYTES],
        const polyveck *t1);
void DILITHIUM_pack_sk(
        uint8_t sk[DILITHIUM_CRYPTO_SECRETKEYBYTES],
        const uint8_t rho[SEEDBYTES],
        const uint8_t key[SEEDBYTES],
        const uint8_t tr[SEEDBYTES],
        const polyvecl *s1,
        const polyveck *s2,
        const polyveck *t0);
void DILITHIUM_pack_sig(
        uint8_t sig[DILITHIUM_CRYPTO_SECRETKEYBYTES],
        const polyvecl *z, const polyveck *h, const poly *c);

void DILITHIUM_unpack_pk(
        uint8_t rho[SEEDBYTES],
        polyveck *t1,
        const uint8_t pk[DILITHIUM_CRYPTO_PUBLICKEYBYTES]);
void DILITHIUM_unpack_sk(
        uint8_t rho[SEEDBYTES],
        uint8_t key[SEEDBYTES],
        uint8_t tr[CRHBYTES],
        polyvecl *s1,
        polyveck *s2,
        polyveck *t0,
        const uint8_t *sk);
int DILITHIUM_unpack_sig(
        polyvecl *z,
        polyveck *h,
        poly *c,
        const uint8_t sig[DILITHIUM_CRYPTO_BYTES]);

#endif
