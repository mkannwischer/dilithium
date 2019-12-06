#ifndef DILITHIUM_SIGN_H
#define DILITHIUM_SIGN_H

#include "api.h"
#include "params.h"
#include "poly.h"
#include "polyvec.h"

void DILITHIUM_expand_mat(polyvecl mat[K], const uint8_t rho[SEEDBYTES]);
void DILITHIUM_challenge(poly *c, const uint8_t mu[CRHBYTES],
                         const polyveck *w1);
#endif
