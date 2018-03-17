#include <Arduino.h>
#include <pnew.cpp>

#include <serstream>
#include <string>

/*
 * Test std::string
 */

struct TestString {

  static void RunTest() {

    std::ohserialstream serial(Serial);
    std::string str;
    char c;

    for(c='A';c<='Z';c++)
      str+=c;

    serial << str << std::endl;
  }

};

TestString s;

void setup() {
    Serial.begin(115200);
}

void loop() {
    delay(1000);
    s.RunTest();
}

