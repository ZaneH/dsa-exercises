#ifndef INCLUDE_RING_BUFFER_RING_BUFFER_H_
#define INCLUDE_RING_BUFFER_RING_BUFFER_H_

#include <cstdint>
#include <iostream>

namespace dsa {
template <typename T, uint64_t capacity = 0>
class RingBuffer {
 public:
  RingBuffer() { std::cout << "Constructor called\n"; }
  ~RingBuffer() { std::cout << "Destructor called\n"; }
};
}  // namespace dsa

#endif  // !INCLUDE_RING_BUFFER_RING_BUFFER_H_
