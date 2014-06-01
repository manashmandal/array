Array
=====

Fixed Size Array C++ Abstraction for Arduino.

Usage
=====

- Construction

  (1) Default Constructor:   array\<type, size> x;
 
      array<int, 10> x; // integer array with size equals to 10;

  (2) From Iterator Range:   array\<type, size> x(I first, I last);
  
      int x[] = {0, 1, 2, 3, 4, 5, 6, 7};
      array<int, 10> y(x, x+8); // y now have {0, 1, 2, 3, 4, 5, 6, 7}
      array<int, 3> z(begin(y), end(y)); // z now have {0, 1, 2}     

- Iterators

  (1) Get first element iterator:    iterator begin(array& x);


- Insert/Remove Element at end with bound checking (slow):

  (1) Insert Element at End:   void push_back(const T& val);
  
      array<int, 10> x;
      
      for (uint8_t i = 0; i < 20; ++i) {
        x.push_back(i);
      }
      // x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

  (2) Remove Element at End:   void pop_back();
  
      array<int, 10> x;
      x.push_back(150); // x = {150}
      x.push_back(-150);  // x = {150, -150}
      x.pop_back();
      // x = {150}
      
      
- Insert/Remove Element at end without bound checking (fast):

   (1) Iterator Deference, Increment and Decrement. 
   
      // Should be used when implementing algorithms.
      array<int, 10> x;
      array<int, 10>::iterator it = x.end();
      for (uint8_t i = 0; i < 5; ++i) {
        *it = i;  
        ++it;
      }
      // x = {1, 2, 3, 4, 5}
      
      --it;
      // x = {1, 2, 3, 4}


- Capacity

  (1) Get Array Current Size:    size_type size() const;
      
      array<int, 10> x;
      x.push_back(50); 
      x.size(); // will return 1;
  
  (2) Get Array Maximum Size:    size_type max_size() const;
      
      array<int, 10> x;
      x.max_size(); // will return 10;
      
  (3) Check if Array is Empty:    bool empty() const;
      
      array<int, 10> x;
      x.empty(); // will return true;
  
  (4) Check if Array is Full:    bool full() const;
      
      array<int, 10> x;
      for (uint8_t i = 0; i < 20; ++i) {
        x.push_back(i);
      }
      x.full(); // will return true;
      
