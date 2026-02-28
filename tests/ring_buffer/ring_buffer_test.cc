#include <gtest/gtest.h>
#include <ring_buffer/ring_buffer.h>

#include <cstdint>

namespace dsa {
TEST(RingBuffer, BasicPushPopFIFO) {
  // Arrange
  dsa::RingBuffer<uint8_t, 8> buf = RingBuffer<uint8_t, 8>();

  // Act
  buf.push(1);
  buf.push(3);
  buf.push(3);
  buf.push(7);

  // Assert
  EXPECT_EQ(buf.capacity(), 8);
  EXPECT_EQ(buf.pop(), 1);
  EXPECT_EQ(buf.pop(), 3);
  EXPECT_EQ(buf.pop(), 3);
  EXPECT_EQ(buf.pop(), 7);
}

TEST(RingBuffer, WrapAround) {
  // Arrange
  dsa::RingBuffer<uint8_t, 2> buf = RingBuffer<uint8_t, 2>();

  // Act
  buf.push(1);
  buf.push(3);
  buf.push(3);
  buf.push(7);

  // Assert
  EXPECT_EQ(buf.capacity(), 2);
  EXPECT_EQ(buf.pop(), 3);
  EXPECT_EQ(buf.pop(), 7);
  EXPECT_EQ(buf.pop(), 3);
}

TEST(RingBuffer, PopWhenEmpty) {
  // Arrange
  dsa::RingBuffer<uint8_t, 2> buf = RingBuffer<uint8_t, 2>();

  // Act
  auto val = buf.pop();

  // Assert
  EXPECT_EQ(buf.capacity(), 2);
  EXPECT_EQ(val, 2);
}
}  // namespace dsa
