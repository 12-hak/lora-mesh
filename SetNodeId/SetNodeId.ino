
#include <EEPROM.h>

#ifdef ESP32
#define EEPROM_SIZE 1
#endif
// change this to be the ID of your node in the mesh network
uint8_t nodeId = 1;

void setup() {
  Serial.begin(115200);
  while (!Serial) ; // Wait for serial port to be available
  #ifdef ESP32
  EEPROM.begin(EEPROM_SIZE); // initialize EEPROM with predefined size
  #endif

  Serial.println("setting nodeId...");

  EEPROM.write(0, nodeId);
  Serial.print(F("set nodeId = "));
  Serial.println(nodeId);
  #ifdef ESP32
  EEPROM.commit();
  #endif

  uint8_t readVal = EEPROM.read(0);

  Serial.print(F("read nodeId: "));
  Serial.println(readVal);

  if (nodeId != readVal) {
    Serial.println(F("*** FAIL ***"));
  } else {
    Serial.println(F("SUCCESS"));
  }
}

void loop() {

}
