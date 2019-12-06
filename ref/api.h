#ifndef DILITHIUM_API_H
#define DILITHIUM_API_H

#include <stddef.h>
#include <stdint.h>

#if MODE == 1
#define DILITHIUM_CRYPTO_PUBLICKEYBYTES 896U
#define DILITHIUM_CRYPTO_SECRETKEYBYTES 2096U
#define DILITHIUM_CRYPTO_BYTES 1387U

#ifndef USE_AES
#define DILITHIUM_CRYPTO_ALGNAME "Dilithium1"
#else
#define DILITHIUM_CRYPTO_ALGNAME "Dilithium1-AES"
#endif

#elif MODE == 2
#define DILITHIUM_CRYPTO_PUBLICKEYBYTES 1184U
#define DILITHIUM_CRYPTO_SECRETKEYBYTES 2800U
#define DILITHIUM_CRYPTO_BYTES 2044U

#ifndef USE_AES
#define DILITHIUM_CRYPTO_ALGNAME "Dilithium2"
#else
#define DILITHIUM_CRYPTO_ALGNAME "Dilithium2-AES"
#endif

#elif MODE == 3
#define DILITHIUM_CRYPTO_PUBLICKEYBYTES 1472U
#define DILITHIUM_CRYPTO_SECRETKEYBYTES 3504U
#define DILITHIUM_CRYPTO_BYTES 2701U

#ifndef USE_AES
#define DILITHIUM_CRYPTO_ALGNAME "Dilithium3"
#else
#define DILITHIUM_CRYPTO_ALGNAME "Dilithium3-AES"
#endif

#elif MODE == 4
#define DILITHIUM_CRYPTO_PUBLICKEYBYTES 1760U
#define DILITHIUM_CRYPTO_SECRETKEYBYTES 3856U
#define DILITHIUM_CRYPTO_BYTES 3366U

#ifndef USE_AES
#define DILITHIUM_CRYPTO_ALGNAME "Dilithium4"
#else
#define DILITHIUM_CRYPTO_ALGNAME "Dilithium4-AES"
#endif

#endif

int DILITHIUM_crypto_sign_keypair(uint8_t *pk, uint8_t *sk);

int DILITHIUM_crypto_sign(uint8_t *sm, size_t *smlen,
                          const uint8_t *msg, size_t len,
                          const uint8_t *sk);

int DILITHIUM_crypto_sign_open(uint8_t *m, size_t *mlen,
                               const uint8_t *sm, size_t smlen,
                               const uint8_t *pk);

int DILITHIUM_crypto_sign_signature(
    uint8_t *sig, size_t *siglen,
    const uint8_t *m, size_t mlen, const uint8_t *sk);

int DILITHIUM_crypto_sign_verify(
    const uint8_t *sig, size_t siglen,
    const uint8_t *m, size_t mlen, const uint8_t *pk);

#ifdef NIST_COMPATIBLE
// This exposes the NIST api
#define crypto_sign_keypair          DILITHIUM_crypto_sign_keypair
#define crypto_sign                  DILITHIUM_crypto_sign
#define crypto_sign_open             DILITHIUM_crypto_sign_open

#define CRYPTO_ALGNAME               DILITHIUM_CRYPTO_ALGNAME
#define CRYPTO_PUBLICKEYBYTES        DILITHIUM_CRYPTO_PUBLICKEYBYTES
#define CRYPTO_SECRETKEYBYTES        DILITHIUM_CRYPTO_SECRETKEYBYTES
#define CRYPTO_BYTES                 DILITHIUM_CRYPTO_BYTES
#endif


#endif
