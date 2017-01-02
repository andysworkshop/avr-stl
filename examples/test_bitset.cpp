#include <Arduino.h>
#include <pnew.cpp>

#include <HardwareSerial.h>
#include <serstream>
#include <bitset>

/*
 * Test std::bitset
 */

struct TestBitset {

  static void RunTest() {

    std::ohserialstream serial(Serial);

    std::bitset<64> mybits(0);

    // set bits 63 and 31 using
    // different methods

    mybits[63]=1;
    mybits|=0x80000000;

    serial << mybits << std::endl;
  }

};

TestBitset b;

void setup() {
    Serial.begin(115200);
}

void loop() {
    delay(1000);
    b.RunTest();
}
