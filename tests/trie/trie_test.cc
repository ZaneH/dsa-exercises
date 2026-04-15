#include <gtest/gtest.h>
#include <trie/trie.h>

namespace dsa {
TEST(Trie, BasicInsertion) {
  // Arrange
  dsa::Trie tree = dsa::Trie();

  // Act
  tree.insert(std::array<size_t, 4>{192, 168, 0, 1});
  tree.insert(std::array<size_t, 4>{192, 168, 0, 2});
  tree.insert(std::array<size_t, 4>{192, 168, 0, 3});
  tree.insert(std::array<size_t, 4>{192, 168, 0, 4});

  tree.print();

  // Assert
  // TODO: Make assertions
}
}  // namespace dsa
