#ifndef ESP32AES_H_
#define ESP32AES_H_

#include <aes/esp_aes.h>

class ESP32AES {
    public:
        ESP32AES(const char* key);
        void encrypt(unsigned char input[16], unsigned char output[16]);
        void decrypt(unsigned char input[16], unsigned char output[16]);
    private:
        esp_aes_context aes;
    protected:


};

#endif