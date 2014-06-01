/*
  Copyright (c) 2014 Rodolfo Picoreti

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "Arduino.h"
#include "algorithm.h"

#define SemiRegular typename // T() = 
#define Regular typename  // T() = == !=  
#define TotallyOrdered typename // T() = == != > >= < <= 

template <SemiRegular T, size_t S>
struct array {
  typedef T value_type;
  typedef size_t size_type;
  typedef T& reference;
  typedef const T& const_reference;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T* iterator;
  typedef const T* const_iterator;
private:
  value_type data[S];
  #define first data
  iterator last;
  #define end_of_storage data+S
public:
  array() : last(first) {}
  array(const size_type& cap) : last(first) { reserve(cap); }
  array(iterator s_first, iterator s_last) : last(first) {
    last = copy(s_first, s_last, first, end_of_storage);
  }
  array(const_iterator s_first, const_iterator s_last) : last(first) {
    last = copy(s_first, s_last, first, end_of_storage);
  }

  void push_back(const_reference value) {
    if (full()) return;
    *last = value;
    ++last;  
  }
  void pop_back() { 
    if (empty()) return;
    --last; 
  }
  
  reference operator[](const size_type& i) { return *(first + i); }
  const_reference operator[](const size_type& i) const { return *(first + i); }

  size_type size() const { return (last - first); } 
  size_type max_size() const { return S; } 
  bool empty() const { return first == last; } 
  bool full() const { return last == data+S; }
  void reserve(const size_type& new_cap) { 
    if (new_cap > S) return;
    last = first + new_cap;
  }

  iterator begin() { return first; }
  const_iterator begin() const { return first; }

  friend 
  iterator begin(array& x) { return x.begin(); }
  friend 
  const_iterator begin(const array& x) { return x.begin(); }

  iterator end() { return last; }
  const_iterator end() const { return last; }

  friend 
  iterator end(array& x) { return x.end(); }
  friend 
  const_iterator end(const array& x) { return x.end(); }
};

template <Regular T, size_t S>
bool operator==(array<T, S>& x, array<T, S>& y) {
  if (x.size() != y.size()) return false;

  typedef typename array<T, S>::iterator I;
  I first1 = begin(x);
  I last = end(x);
  I first2 = begin(y);

  while (first1 != last) {
    if (*first1 != *first2) return false;
    ++first1;
    ++first2;
  }

  return true;
}

template <Regular T, size_t S>
bool operator!=(array<T, S>& x, array<T, S>& y) {
  return !(x == y);
}

template <TotallyOrdered T, size_t S>
bool operator<(array<T, S>& x, array<T, S>& y) {
  typedef typename array<T, S>::iterator I;
  I first1 = begin(x);
  I last1 = end(x);
  I first2 = begin(y);
  I last2 = end(y);

  while (first1 != last1) {
    if (first2 == last2 || *first2 < *first1) return false;
    if (*first1 < *first2) return true;
    ++first1; 
    ++first2;
  }

  return (first2 != last2);
}

template <TotallyOrdered T, size_t S>
bool operator>(array<T, S>& x, array<T, S>& y) {
  return y < x; // x > y -> y < x
}

template <TotallyOrdered T, size_t S>
bool operator<=(array<T, S>& x, array<T, S>& y) {
  return !(x > y);
}

template <TotallyOrdered T, size_t S>
bool operator>=(array<T, S>& x, array<T, S>& y) {
  return !(x < y);
}

#endif