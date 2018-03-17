#include <Arduino.h>
#include <pnew.cpp>

#include <HardwareSerial.h>
#include <serstream>
#include <iomanip>  // for setprecision()
#include <sstream>

/*
 * Run some tests on the hardware serial stream
 */

struct TestSerial {
    
  static void RunTest() {

    std::ohserialstream serial(Serial);

    serial << "Hello world" << std::endl
           << "Floating point: "
           << std::setprecision(3) << 3.14159 << std::endl;
  }
};

TestSerial s;

void setup() {
    Serial.begin(115200);
}

void loop() {
    delay(1000);
    s.RunTest();
}

