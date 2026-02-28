#ifndef INCLUDE_RING_BUFFER_RING_BUFFER_H_
#define INCLUDE_RING_BUFFER_RING_BUFFER_H_

#include <cstdint>
#include <iostream>

namespace dsa {
template <typename T, uint64_t N = 0>
class RingBuffer {
 public:
  constexpr RingBuffer() {
    // Assert that capacity is a power of 2
    static_assert((N & (N - 1)) == 0);
  }
  ~RingBuffer() { std::cout << "Destructor called\n"; }

  uint64_t capacity() { return N; }
  void push(T elem) { (void)elem; }
  T pop() {}

 private:
  std::array<T, N> data_;
  std::uint64_t head_idx_;
  std::uint64_t tail_idx_;
};
}  // namespace dsa

#endif  // !INCLUDE_RING_BUFFER_RING_BUFFER_H_
