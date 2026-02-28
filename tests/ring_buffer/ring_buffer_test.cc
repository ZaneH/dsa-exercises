#include <gtest/gtest.h>
#include <ring_buffer/ring_buffer.h>

#include <cstdint>

namespace dsa {
TEST(RingBuffer, Demo) {
  dsa::RingBuffer<uint8_t, 8> buf = RingBuffer<uint8_t, 8>();
  EXPECT_EQ(buf.capacity(), 8);
}
}  // namespace dsa
