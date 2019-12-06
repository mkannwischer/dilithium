#ifndef REJSAMPLE_H
#define REJSAMPLE_H

#include <stdint.h>

#include "poly.h"

unsigned int DILITHIUM_rej_uniform(
        uint32_t *r,
        unsigned int len,
        const uint8_t *buf,
        unsigned int buflen);

unsigned int DILITHIUM_rej_eta(
        uint32_t *r,
        unsigned int len,
        const uint8_t *buf,
        unsigned int buflen);

unsigned int DILITHIUM_rej_gamma1m1(
        uint32_t *r,
        unsigned int len,
        const uint8_t *buf,
        unsigned int buflen);

#endif
