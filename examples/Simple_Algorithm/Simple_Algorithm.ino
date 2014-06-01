#include <array.h>

/* 
 (Example 1) - Array Library 
 Algorithm creation example without templates.
 
 Created 2014 
 by Rodolfo Picoreti
 https://github.com/rodolfo-picoreti/array
 */


// fill the array from first to last with val, val+1, ...
void fill(int* first, int* last, int val) {
  while (first != last) {
    *first = val; // set this element
    ++first; // go to next element
    ++val; 
  }
}

// sum the array elements from first to last;
int accumulate(int* first, int* last) {
  int result = 0;
  while (first != last) {
    result += *first; // accumulate result
    ++first; // go to next element
  }
  return result;
}

array<int, 10> x;

void setup() {
  Serial.begin(9600);

  fill(begin(x), bound(x), 50);
  int sum = accumulate(begin(x), end(x));

  Serial.println(sum);
}

void loop() {
}
