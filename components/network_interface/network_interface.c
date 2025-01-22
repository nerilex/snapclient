/*
 * network_interface.c
 *
 *  Created on: Jan 22, 2025
 *      Author: karl
 */

/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

#include <stdio.h>
#include <string.h>

#include "esp_event.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "esp_netif.h"
#include "esp_wifi_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "include/eth_interface.h"
#include "sdkconfig.h"

#if CONFIG_SNAPCLIENT_USE_INTERNAL_ETHERNET || \
    CONFIG_SNAPCLIENT_USE_SPI_ETHERNET
#include "eth_interface.h"
#endif

#include "wifi_interface.h"

static const char *TAG = "NET_IF";

/**
 * @brief Checks the netif description if it contains specified prefix.
 * All netifs created withing common connect component are prefixed with the
 * module TAG, so it returns true if the specified netif is owned by this module
 */
bool network_is_our_netif(const char *prefix, esp_netif_t *netif) {
  return strncmp(prefix, esp_netif_get_desc(netif), strlen(prefix) - 1) == 0;
}

void network_init(void) {
  esp_netif_init();
  ESP_ERROR_CHECK(esp_event_loop_create_default());

#if CONFIG_SNAPCLIENT_USE_INTERNAL_ETHERNET || \
    CONFIG_SNAPCLIENT_USE_SPI_ETHERNET
  eth_start();
#endif

  wifi_start();
}
