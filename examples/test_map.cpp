#include <Arduino.h>
#include <pnew.cpp>

#include <serstream>
#include <map>


/*
 * Test std::map
 */

struct TestMap {

  static void RunTest() {

    std::ohserialstream serial(Serial);

    std::map<int,const char *> days;
    int i;

    days[1]="Monday";
    days[2]="Tuesday";
    days[3]="Wednesday";
    days[4]="Thursday";
    days[5]="Friday";
    days[6]="Saturday";
    days[7]="Sunday";

    for(i=1;i<=7;i++)
      serial << days[i] << std::endl;
      
    serial << std::endl;
  }
};

TestMap m;

void setup() {
    Serial.begin(115200);
}

void loop() {
    delay(1000);
    m.RunTest();
}
