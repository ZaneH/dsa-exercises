#ifndef INCLUDE_RING_BUFFER_RING_BUFFER_H_
#define INCLUDE_RING_BUFFER_RING_BUFFER_H_

#include <array>
#include <cstdint>

namespace dsa {
template <typename T, uint64_t N = 0>
class RingBuffer {
 public:
  constexpr RingBuffer() {
    // Assert that capacity is a power of 2
    static_assert((N & (N - 1)) == 0);
  }
  ~RingBuffer() {
    for (std::size_t i = 0; i < capacity(); i++) {
      data_[i].~T();
    }
  }

  constexpr uint64_t capacity() { return N; }
  void push(T elem) { data_[to_index(head_idx_++)] = elem; }
  T pop() { return data_[to_index(tail_idx_++)]; }

 private:
  constexpr uint64_t to_index(uint64_t n) { return ((N - 1) & n); }

  std::array<T, N> data_;
  uint64_t head_idx_ = 0;
  uint64_t tail_idx_ = 0;
};
}  // namespace dsa

#endif  // !INCLUDE_RING_BUFFER_RING_BUFFER_H_
