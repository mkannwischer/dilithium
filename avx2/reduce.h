#ifndef REDUCE_H
#define REDUCE_H

#include <stdint.h>

void DILITHIUM_reduce_avx(uint32_t a[N]);
void DILITHIUM_csubq_avx(uint32_t a[N]);

#endif
