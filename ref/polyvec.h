#ifndef DILITHIUM_POLYVEC_H
#define DILITHIUM_POLYVEC_H

#include <stdint.h>

#include "params.h"
#include "poly.h"

/* Vectors of polynomials of length L */
typedef struct {
  poly vec[L];
} polyvecl;

void DILITHIUM_polyvecl_freeze(polyvecl *v);

void DILITHIUM_polyvecl_add(polyvecl *w, const polyvecl *u, const polyvecl *v);

void DILITHIUM_polyvecl_ntt(polyvecl *v);
void DILITHIUM_polyvecl_pointwise_acc_invmontgomery(poly *w,
                                                    const polyvecl *u,
                                                    const polyvecl *v);

int DILITHIUM_polyvecl_chknorm(const polyvecl *v, uint32_t B);



/* Vectors of polynomials of length K */
typedef struct {
  poly vec[K];
} polyveck;

void DILITHIUM_polyveck_reduce(polyveck *v);
void DILITHIUM_polyveck_csubq(polyveck *v);
void DILITHIUM_polyveck_freeze(polyveck *v);

void DILITHIUM_polyveck_add(polyveck *w, const polyveck *u, const polyveck *v);
void DILITHIUM_polyveck_sub(polyveck *w, const polyveck *u, const polyveck *v);
void DILITHIUM_polyveck_shiftl(polyveck *v);

void DILITHIUM_polyveck_ntt(polyveck *v);
void DILITHIUM_polyveck_invntt_montgomery(polyveck *v);

int DILITHIUM_polyveck_chknorm(const polyveck *v, uint32_t B);

void DILITHIUM_polyveck_power2round(polyveck *v1, polyveck *v0, const polyveck *v);
void DILITHIUM_polyveck_decompose(polyveck *v1, polyveck *v0, const polyveck *v);
unsigned int DILITHIUM_polyveck_make_hint(polyveck *h,
                                          const polyveck *v0,
                                          const polyveck *v1);
void DILITHIUM_polyveck_use_hint(polyveck *w, const polyveck *v, const polyveck *h);

#endif
