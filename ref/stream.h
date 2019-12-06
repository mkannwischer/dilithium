#ifndef DILITHIUM_STREAM_H
#define DILITHIUM_STREAM_H 

#include <stdint.h>

#include "params.h"
#include "fips202.h"

void DILITHIUM_shake128_stream_init(
    shake128ctx *state, const uint8_t seed[SEEDBYTES], uint16_t nonce);

void DILITHIUM_shake256_stream_init(
    shake256ctx *state, const uint8_t seed[CRHBYTES], uint16_t nonce);

#endif
