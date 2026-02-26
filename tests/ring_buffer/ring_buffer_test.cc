#include <gtest/gtest.h>
#include <ring_buffer/ring_buffer.h>

#include <cstdint>

namespace dsa {
TEST(RingBuffer, Demo) {
  dsa::RingBuffer<uint8_t, 8> buf = RingBuffer<uint8_t, 8>();
  (void)buf;
}
}  // namespace dsa
