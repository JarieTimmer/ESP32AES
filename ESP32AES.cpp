#include "ESP32AES.h"
#include <string.h>
        /**
        * Constructor for the ESP32AES class. Key must be 16 bytes and const.
        * initializes the ESP32 AES hardware acceleration.
        */
        ESP32AES::ESP32AES(const char* key) {
            esp_aes_init(&this->aes);
            esp_aes_setkey(&this->aes, (const unsigned char*) key, strlen(key) * 8);
        };
        /**
        * Encrypts the data given in input and overrides the content of output with encrypted data
        * Input and output must be type of unsigned char[16]
        */
        void ESP32AES::encrypt(unsigned char input[16], unsigned char output[16]) {
            esp_aes_crypt_ecb(&this->aes, ESP_AES_ENCRYPT, (const unsigned char*) input, output);
        };
        /**
        * Decrypts the data given in input and overrides the content of output with decrypted data
        * Input and output must be type of unsigned char[16]
        */
        void ESP32AES::decrypt(unsigned char input[16], unsigned char output[16]) {
            esp_aes_crypt_ecb(&this->aes, ESP_AES_DECRYPT, (const unsigned char*) input, output);
        }