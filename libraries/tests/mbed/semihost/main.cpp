#include "test_env.h"

#define MAC_VENDOR_ARM_0    0x00
#define MAC_VENDOR_ARM_1    0x02
#define MAC_VENDOR_ARM_2    0xF7

int main() {
    char uid[DEVICE_ID_LENGTH + 1] = {0};
    bool result = true;

    const int ret = mbed_interface_uid(uid);
    if (ret == 0) {
        printf("UID: %s\r\n", uid);
    }
    else {
        result = false;
    }

    char mac[6] = {0};  // @param mac A 6-byte array to write the MAC address
    mbed_mac_address(mac);
    printf("MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    if (mac[0] == MAC_VENDOR_ARM_0 &&
        mac[1] == MAC_VENDOR_ARM_1 &&
        mac[2] == MAC_VENDOR_ARM_2) {
        printf("MAC Address Prefix: 00:02:F7, Vendor: ARM\r\n");
    }

    notify_completion(result);
    return 0;
}
