/*
 * network_interface.h
 *
 *  Created on: Jan 22, 2025
 *      Author: karl
 */

#ifndef COMPONENTS_NETWORK_INTERFACE_INCLUDE_NETWORK_INTERFACE_H_
#define COMPONENTS_NETWORK_INTERFACE_INCLUDE_NETWORK_INTERFACE_H_

#include <stdbool.h>

#include "esp_netif.h"

#define NETWORK_INTERFACE_DESC_STA "sta"
#define NETWORK_INTERFACE_DESC_ETH "eth"

bool network_is_our_netif(const char *prefix, esp_netif_t *netif);
void network_init(void);

#endif /* COMPONENTS_NETWORK_INTERFACE_INCLUDE_NETWORK_INTERFACE_H_ */
