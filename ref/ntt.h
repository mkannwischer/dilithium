#ifndef DILITHIUM_NTT_H
#define DILITHIUM_NTT_H

#include <stdint.h>

#include "params.h"

void DILITHIUM_ntt(uint32_t p[N]);
void DILITHIUM_invntt_frominvmont(uint32_t p[N]);

#endif
