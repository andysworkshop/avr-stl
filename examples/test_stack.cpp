#include <HardwareSerial.h>

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

