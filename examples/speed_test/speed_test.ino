#include <Arduino.h>
#include <string.h>
#include <stdio.h>
#include "ESP32AES.h"

#define BLOCK_SIZE 16

const char* key = "abcdefghijklmnop";
unsigned char input[BLOCK_SIZE] = {0x01,0x02,0x03,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char encrypted_input[BLOCK_SIZE];
ESP32AES aes32 = ESP32AES(key);

void setup() {
  Serial.begin(115200);
}

void loop() {
  int32_t start = ESP.getCycleCount();
  aes32.encrypt(input, encrypted_input);
  int32_t end = ESP.getCycleCount();
  float enctime = (end-start)/240.0;
  Serial.print("Encryption time: ");
  Serial.print(enctime);
  Serial.println(" microseconds");
  
  start = ESP.getCycleCount();
  aes32.decrypt(encrypted_input, input);
  end = ESP.getCycleCount();
  enctime = (end-start)/240.0;
  Serial.print("Decryption time: ");
  Serial.print(enctime);
  Serial.println(" microseconds");
}