#include <array.h>

/* 
  (Example 1) - Array Library 

  Simple algorithm usage example.

  Created 2014 
  by Rodolfo Picoreti
  https://github.com/rodolfo-picoreti/array
*/

 // Create array of size 10 and reserve everything;
array<int, 10> x(10);

void setup() {
  Serial.begin(9600);

  iota(begin(x), end(x), 50); // x = {50, 51, 52, 53, 54}
  print_range(begin(x), end(x), Serial); // print x from begin to end
  int sum = 0;
  accumulate(begin(x), end(x), sum); // compute the array sum
  Serial.println(sum);
}

void loop() {
}
