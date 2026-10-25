#include <SPI.h>
#include <RF24.h>
#include <driver/i2s.h>

// --- 1. NRF24L01+ RADIO PIN DEFINITIONS ---
#define NRF_CE_PIN  9
#define NRF_CSN_PIN 10
RF24 radio(NRF_CE_PIN, NRF_CSN_PIN);
const byte address[6] = "S3Deck"; // Communication Address

// --- 2. I2S AUDIO PIN DEFINITIONS ---
// Shared Clock Pins
#define I2S_SCK_PIN  7   // BCLK for Amp & SCK for Mic
#define I2S_WS_PIN   20  // LRC for Amp & WS for Mic
// Specific Data Pins
#define I2S_DIN_PIN  1   // Amplifier Data Input (DIN)
#define I2S_SD_PIN   3   // Microphone Data Output (SD)

void setup() {
  Serial.begin(115200);
  
  // Initialize NRF24L01+ Radio
  if (!radio.begin()) {
    Serial.println("NRF24L01 initialization failed!");
    while (1);
  }
  radio.openWritingPipe(address);
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening(); // Set as transmitter initially (or start listening)
  
  Serial.println("CyberDeck S3 Initialized Successfully!");
}

void loop() {
  // Here you will add your audio sampling from INMP441 
  // and packet transmission/reception via NRF24L01+.
  
  delay(1000);
}
