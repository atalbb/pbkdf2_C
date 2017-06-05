#include <stdio.h>
#include <string.h>
#include "wf_universal_driver.h"
void display(uint8_t * buff){
    uint8_t i =0;
    for(i=0;i<32;i++){

    }
}
void WF_WpaConvPassphraseToKey(t_wpaKeyInfo *p_keyInfo)
{
    uint8_t binaryKey[WF_WPA_KEY_LENGTH];
    int i = 0;
    p_keyInfo->key[p_keyInfo->keyLength] = '\0';   /** make sure passphrase is terminated*/

    /** generate the binary key*/
    /** DK = PBKDF2(Passphrase,Salt,c,dklen)*/
    printf("SSID = %s\nSSID Len = %d\nPWD = %s\nPWD Len = %d\r\n",p_keyInfo->ssid,p_keyInfo->ssidLen,p_keyInfo->key,p_keyInfo->keyLength);
    pbkdf2_sha1((const char *)p_keyInfo->key, /** passphrase*/
                (const char *)p_keyInfo->ssid, /** Salt */
                p_keyInfo->ssidLen,
                4096, /** c */
                binaryKey, /** binary key will be written to this field(DK) */
                32); /**dklen */
    /*printf("BK:\r\n");
    for(i=0;i<32;i++){
        printf("%x ",binaryKey[i]);
    }
    printf("\r\n");*/
    /** overwrite the passphrase with binary key*/
    memcpy(p_keyInfo->key, binaryKey, WF_WPA_KEY_LENGTH);

    /** overwrite the length with the length of the binary key (always 32)*/
    p_keyInfo->keyLength = WF_WPA_KEY_LENGTH;
}
