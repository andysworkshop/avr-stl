#include <Arduino.h>
#include <pnew.cpp>

#include <serstream>
#include <set>

/*
 * Test std::set
 */

struct TestSet {

  static void RunTest() {

    std::ohserialstream serial(Serial);

    std::set<int> s1,s2;
    int i;

    for(i=0;i<10;i++)
      s1.insert(i);

    for(i=5;i<15;i++)
      s2.insert(i);

    std::set_intersection(
        s1.begin(),s1.end(),
        s2.begin(),s2.end(),
        std::ostream_iterator<int>(serial," "));

    serial << std::endl;
  }
};


TestSet s;

void setup() {
    Serial.begin(115200);
}

void loop() {
    delay(1000);
    s.RunTest();
}
