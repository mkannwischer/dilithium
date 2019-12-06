#ifndef DILITHIUM_PACKING_H
#define DILITHIUM_PACKING_H

#include "params.h"
#include "polyvec.h"

void DILITHIUM_pack_pk(uint8_t *pk,
                       const uint8_t *rho, const polyveck *t1);
void DILITHIUM_pack_sk(uint8_t *sk,
                       const uint8_t *rho,
                       const uint8_t *key,
                       const uint8_t *tr,
                       const polyvecl *s1,
                       const polyveck *s2,
                       const polyveck *t0);
void DILITHIUM_pack_sig(uint8_t *sig,
                        const polyvecl *z, const polyveck *h, const poly *c);

void DILITHIUM_unpack_pk(uint8_t *rho, polyveck *t1,
                         const uint8_t *pk);
void DILITHIUM_unpack_sk(uint8_t *rho,
                         uint8_t *key,
                         uint8_t *tr,
                         polyvecl *s1,
                         polyveck *s2,
                         polyveck *t0,
                         const uint8_t *sk);
int DILITHIUM_unpack_sig(polyvecl *z, polyveck *h, poly *c,
                         const uint8_t *sig);

#endif
