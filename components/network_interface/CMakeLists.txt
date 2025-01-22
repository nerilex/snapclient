idf_component_register(SRCS "network_interface.c" "eth_interface.c" "wifi_interface.c"
                       INCLUDE_DIRS "include"
                       PRIV_REQUIRES driver esp_eth esp_netif esp_timer nvs_flash
                       REQUIRES esp_wifi)
