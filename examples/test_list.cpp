#include <Arduino.h>
#include <pnew.cpp>

#include <HardwareSerial.h>
#include <serstream>
#include <list>

/*
 * Test std::list
 */

struct TestList {

  static void RunTest() {

    std::ohserialstream serial(Serial);
    std::list<int> lst;
    std::list<int>::const_iterator it;
    int i;

    for(i=0;i<50;i++)
      lst.push_back(i);
 
    for(it=lst.begin();it!=lst.end();it++)
      serial << *it << ' ';

    serial << std::endl;
  }

};

TestList l;

void setup() {
    Serial.begin(115200);
}

void loop() {
    delay(1000);
    l.RunTest();
}
