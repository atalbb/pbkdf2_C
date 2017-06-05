#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "wf_universal_driver.h"
#include "adapter.h"

void dump(uint8_t *buff, int buff_len){
    int i =0;
    for(i=0;i<buff_len;i++){
        if(i%16 == 0){
            printf("\r\n");
        }
        printf("%.2x ",buff[i]);
    }
}
uint8_t wpaCalPSK(const char * szSsid, const char * szPassphrase, WPA2KEY  *wpaKey){
     t_wpaKeyInfo wpaInfo; /**hold ssid & ssid length, passphrase & passphrase length*/


    if( szSsid != NULL &&
        szPassphrase != NULL &&
        (wpaInfo.ssidLen = strlen(szSsid)) <= WF_MAX_SSID_LENGTH &&
        (wpaInfo.keyLength = strlen(szPassphrase)) <= WF_MAX_PASSPHRASE_LENGTH )
    {
        printf("Valid SSID and Password\:r\n");
        memcpy(wpaInfo.ssid, szSsid, wpaInfo.ssidLen);
        memcpy(wpaInfo.key, szPassphrase, wpaInfo.keyLength);

        WF_WpaConvPassphraseToKey(&wpaInfo);

        memcpy(wpaKey->rgbKey, wpaInfo.key, sizeof(WPA2KEY));

        return(1);
    }

    return(0);
}
int main()
{
    const char ssid[] = "linksys54gh";
    const char passphrase[] = "radiustest";
//    const char ssid[] = "originalgangster";//HTC One_M8 4996";
//    const char passphrase[] = "og150-test";//"bajracha";
    //const char ssid[] = "originalgangster";//HTC One_M8 4996";
    //const char passphrase[] = "og150-test";//"bajracha";


    WPA2KEY key;
    wpaCalPSK(ssid, passphrase,&key);
    dump(key.rgbKey,32);
    return 0;
}
