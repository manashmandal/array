#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

template <typename I, typename T>
void accumulate(I first, I last, T& x) {
  while (first != last) {
    x += *first; // accumulate result
    ++first; // go to next element
  }
}

template <typename I, typename S>
void print_range(I first, I last, S stream) {
  while (first != last) {
    stream.print(*first);
    stream.print(" ");
    ++first; // go to next element
  }
  stream.print("\r\n");
}

template <typename I, typename T>
void iota(I first, I last, T val) {
  while (first != last) {
    *first = val;
    ++first; // go to next element
    ++val;
  }
}

template<typename I>
I copy(I s_first, I s_last, I d_first, I d_last)
{
  while (s_first != s_last && d_first != d_last) {
    *d_first++ = *s_first++;
  }
  return d_first;
}
#endif