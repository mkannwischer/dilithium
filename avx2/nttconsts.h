#ifndef DILITHIUM_NTTCONSTS_H
#define DILITHIUM_NTTCONSTS_H

#include <immintrin.h>
#include <stdint.h>

#include "params.h"
#include "alignment.h"

typedef ALIGNED_UINT32(8) aligned_uint32x8_t;

typedef ALIGNED_UINT32(N) aligned_uint32xN_t;


extern const aligned_uint32x8_t _DILITHIUM_8xqinv;
extern const aligned_uint32x8_t _DILITHIUM_8xq;
extern const aligned_uint32x8_t _DILITHIUM_8x2q;
extern const aligned_uint32x8_t _DILITHIUM_8x256q;
extern const aligned_uint32x8_t _DILITHIUM_mask;
extern const aligned_uint32x8_t _DILITHIUM_8x23ones;
extern const aligned_uint32x8_t _DILITHIUM_8xdiv;

extern const aligned_uint32xN_t DILITHIUM_zetas;
extern const aligned_uint32xN_t DILITHIUM_zetas_inv;

#endif //DILITHIUM_NTTCONSTS_H

