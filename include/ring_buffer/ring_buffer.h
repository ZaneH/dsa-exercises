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
    static_assert((N & (N - 1)) == 0, "capacity must be a power of 2");
    static_assert(N > 0, "capacity must be greater than 0");
  }

  constexpr uint64_t capacity() const noexcept { return N; }
  constexpr uint64_t size() const noexcept { return size_; }
  constexpr bool empty() const noexcept { return size_ == 0; }
  constexpr bool full() const noexcept { return size_ == N; }

  void push(const T& v) {
    size_++;
    data_[to_index(head_idx_++)] = v;
  }

  void push(const T&& v) {
    size_++;
    data_[to_index(head_idx_++)] = v;
  }

  T* pop() {
    if (size_ == 0) return nullptr;

    size_--;
    return &data_[to_index(tail_idx_++)];
  }

 private:
  constexpr uint64_t to_index(uint64_t n) const noexcept {
    return ((N - 1) & n);
  }

  std::array<T, N> data_;
  uint64_t size_ = 0;
  uint64_t head_idx_ = 0;
  uint64_t tail_idx_ = 0;
};
}  // namespace dsa

#endif  // !INCLUDE_RING_BUFFER_RING_BUFFER_H_
