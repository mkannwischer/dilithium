#ifndef ROUNDING_H
#define ROUNDING_H

#include <stdint.h>
#include "params.h"

uint32_t DILITHIUM_power2round(uint32_t a, uint32_t *a0);
uint32_t DILITHIUM_decompose(uint32_t a, uint32_t *a0);
unsigned int DILITHIUM_make_hint(const uint32_t a0, const uint32_t a1);
uint32_t DILITHIUM_use_hint(const uint32_t a, const unsigned int hint);

#endif
