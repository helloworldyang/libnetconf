/**
 * \file libnetconf_tls.h
 * \author Radek Krejci <rkrejci@cesnet.cz>
 * \brief libnetconf's header for control openssl.
 *
 * Copyright (c) 2012-2014 CESNET, z.s.p.o.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is, and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */

#ifndef LIBNETCONF_TLS_H_
#define LIBNETCONF_TLS_H_

#include <openssl/x509.h>

#include "libnetconf/netconf.h"
#include "libnetconf/transport.h"
#include "libnetconf/callhome.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup tls NETCONF over TLS
 * \brief libnetconf's functions to use TLS
 *
 * Remember, that to make these functions available, libnetconf must be
 * compiled with --enable-tls configure's option.
 */

/**
 * @ingroup tls
 * @brief Set paths to the client certificate and its private key
 *
 * This function takes effect only on client side. It must be used before
 * establishing NETCONF session (including call home) over TLS.
 *
 * @param[in] peer_cert Path to the file containing client certificate
 * @param[in] peer_key Path to the file containing private key for the client
 * certificate. If NULL, key is expected to be stored in the file specified in
 * cert parameter.
 * @param[in] CAfile Location of the CA certificate used to verify the server
 * certificates. For More info, see documentation for
 * SSL_CTX_load_verify_locations() function from OpenSSL.
 * @param[in] CApath Location of the CA certificates used to verify the server
 * certificates. For More info, see documentation for
 * SSL_CTX_load_verify_locations() function from OpenSSL.
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int nc_tls_init(const char* peer_cert, const char* peer_key, const char *CAfile, const char *CApath);

#ifdef __cplusplus
}
#endif

#endif /* LIBNETCONF_H_ */

