/*
 * Getter functions for OpenSSL < 1.1 compatibility. Based on code from:
 * https://wiki.openssl.org/index.php/1.1_API_Changes#Adding_forward-compatible_code_to_older_versions
 * and therefore:
 * Copyright OpenSSL 2016
 * Contents licensed under the terms of the OpenSSL license
 * See http://www.openssl.org/source/license.html for details
 */

#ifndef __OPENSSL_COMPAT_H
#define __OPENSSL_COMPAT_H

#if OPENSSL_VERSION_NUMBER < 0x10100000L

#include <openssl/engine.h>

static inline void
RSA_get0_key( const RSA *r,
              const BIGNUM **n,
              const BIGNUM **e,
              const BIGNUM **d ) {

	if ( n )
		*n = r->n;
	if ( e )
		*e = r->e;
	if ( d )
		*d = r->d;
}

static inline void
RSA_get0_factors( const RSA *r,
                  const BIGNUM **p,
                  const BIGNUM **q ) {

	if ( p )
		*p = r->p;
	if ( q )
		*q = r->q;
}

static inline void
RSA_get0_crt_params( const RSA *r,
                     const BIGNUM **dmp1,
                     const BIGNUM **dmq1,
                     const BIGNUM **iqmp ) {

	if ( dmp1 )
		*dmp1 = r->dmp1;
	if ( dmq1 )
		*dmq1 = r->dmq1;
	if ( iqmp )
		*iqmp = r->iqmp;
}

#endif /* OPENSSL_VERSION_NUMBER */

#endif /* __OPENSSL_COMPAT_H */
