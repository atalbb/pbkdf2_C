#include <inttypes.h>

#define WF_MAX_SSID_LENGTH                  (32)        /** does not include string terminator*/
#define WF_MAX_PASSPHRASE_LENGTH            (64)        /** must include string terminator*/
#define WF_WPA_KEY_LENGTH                   (32)        /** WPA binary key always 32 bytes*/

/**used in t_wpaContext and t_wpsContext*/
typedef struct
{
    uint8_t key[WF_MAX_PASSPHRASE_LENGTH];  /** binary key or passphrase */
    uint8_t keyLength;                      /** number of bytes in binary key (always 32) or passphrase*/
    uint8_t ssid[WF_MAX_SSID_LENGTH];       /** ssid*/
    uint8_t ssidLen;                        /** number of bytes in SSID*/
} t_wpaKeyInfo;
