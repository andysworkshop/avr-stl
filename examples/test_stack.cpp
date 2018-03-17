#include <Arduino.h>
#include <pnew.cpp>

#include <HardwareSerial.h>
#include <serstream>
#include <stack>
#include <vector>

/*
 * Test std::stack
 */

struct TestStack {

  static void RunTest() {

    std::ohserialstream serial(Serial);
    std::stack<int,std::vector<int> > stk;
    int i;

    for(i=0;i<20;i++)
      stk.push(i);

    while(!stk.empty()) {
      serial << stk.top() << ' ';
      stk.pop();
    }

    serial << std::endl;
  }
};

TestStack s;

void setup() {
    Serial.begin(115200);
}

void loop() {
    delay(1000);
    s.RunTest();
}

