#ifndef NTT_H
#define NTT_H

#include <stdint.h>

#include "params.h"
#include "nttconsts.h"

void DILITHIUM_ntt_levels0t2_avx(uint64_t *tmp,
                                 const uint32_t *a,
                                 const uint32_t *zetas);
void DILITHIUM_ntt_levels3t8_avx(uint32_t *a,
                                 const uint64_t *tmp,
                                 const uint32_t *zetas);

void DILITHIUM_invntt_levels0t4_avx(uint64_t *tmp,
                                    const uint32_t *a,
                                    const uint32_t *zetas_inv);
void DILITHIUM_invntt_levels5t7_avx(uint32_t *a,
                                    const uint64_t *tmp,
                                    const uint32_t *zetas_inv);

void DILITHIUM_pointwise_avx(uint32_t *c, const uint32_t *a, const uint32_t *b);
void DILITHIUM_pointwise_acc_avx(uint32_t *c, const uint32_t *a, const uint32_t *b);

#endif
