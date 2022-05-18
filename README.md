# ESP32AES

ESP32 AES Wrapper for the esp_aes hardware library. Encrypts 16 bytes blocks

## Installation

Add the library as .ZIP library in the Arduino IDE

for platform.io add the library in the /lib folder


## Usage

```cpp
#include "ESP32AES/ESP32AES.h"

// set the encryption key
const char* key = "abcdefghijklmnop";

// create two char array's with size 16
unsigned char input[BLOCK_SIZE] = {0x01,0x02,0x03,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char encrypted_input[BLOCK_SIZE];

// create object ESP32AES
ESP32AES aes32 = ESP32AES(key);

// encrypt the given input and copy to encrypted_input
aes32.encrypt(input, encrypted_input);

// decrypt the encrypted input and copy to input
aes32.decrypt(encrypted_input, input);
```

## Functions

```cpp
// constructor
ESP32AES(const char* key);
// encrypt
void encrypt(unsigned char input[16], unsigned char output[16]);
// decrypt
void decrypt(unsigned char input[16], unsigned char output[16]);
```
