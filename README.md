Array
=====

Fixed Size Array C++ Library for Arduino.

Visual Diagram
=====
![](https://raw.githubusercontent.com/rodolfo-picoreti/array/master/array.png)

Usage
=====

- ### Construction

  (1) Default Constructor:   **array\<type, size> x;**
 
      array<int, 10> x; // integer array with size equals to 10;

  (2) Construct and Reserve:  **array\<type, size> x(size_type capacity);**
 
      array<int, 10> x(10); // integer array with size equals to 10 and using full capacity;

  (3) From Iterator Range:   **array\<type, size> x(I first, I last);**
  
      int x[] = {0, 1, 2, 3, 4, 5, 6, 7};
      array<int, 10> y(x, x+8); // y now have {0, 1, 2, 3, 4, 5, 6, 7}
      array<int, 3> z(begin(y), end(y)); // z now have {0, 1, 2}
      

- ### Insert/Remove Element at end with bound checking:

  (1) Insert element at back:   **void push_back(const T& value);**
  
      array<int, 10> x;
      
      for (uint8_t i = 0; i < 20; ++i) {
        x.push_back(i);
      }
      // x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

  (2) Remove element at back:   **void pop_back();**
  
      array<int, 10> x;
      x.push_back(150); // x = {150}
      x.push_back(-150);  // x = {150, -150}
      x.pop_back();
      // x = {150}
      

- ### Capacity

  (1) Get array current size:    **size_type size() const;**
      
      array<int, 10> x;
      x.push_back(50); 
      x.size(); // will return 1;
  
  (2) Get array maximum size:    **size_type max_size() const;**
      
      array<int, 10> x;
      x.max_size(); // will return 10;
      
  (3) Check if array is empty:    **bool empty() const;**
      
      array<int, 10> x;
      x.empty(); // will return true;
  
  (4) Check if array is full:    **bool full() const;**
      
      array<int, 10> x;
      for (uint8_t i = 0; i < 20; ++i) {
        x.push_back(i);
      }
      x.full(); // will return true;

      array<int, 10> y(10);
      y.full(); // will return true;

  (5) Change array capacity: **void reserve(size_type new_capacity);**

      array<int, 10> x;
      x.reserve(10);

      array<int, 10> y;
      y.reserve(14); // do nothing 

- ### Iterators

  (1) Iterator to the first element :    **iterator begin(array& x);**

      array<int, 10> x; 
      begin(x); // returns a pointer to x[0];
      
  (2) Iterator to past the last element:    **iterator end(array& x);**

      array<int, 10> x; 
      end(x); // returns a pointer to x[0];
      x.push_back(4);
      end(x); // returns a pointer to x[1];
            
- ### Insert/Remove Element at end without bound checking:

  // soon