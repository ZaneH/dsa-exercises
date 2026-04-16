#include <gtest/gtest.h>
#include <trie/trie.h>

namespace dsa {
class TrieFixture : public testing::Test {
 public:
  dsa::Trie tree;
  std::array<size_t, 4> ip1;
  std::array<size_t, 4> ip2;
  std::array<size_t, 4> ip3;
  std::array<size_t, 4> ip4;
  std::array<size_t, 4> ip5;

 protected:
  void SetUp() {
    tree = dsa::Trie();
    ip1 = std::array<size_t, 4>{192, 168, 0, 1};
    ip2 = std::array<size_t, 4>{192, 168, 0, 2};
    ip3 = std::array<size_t, 4>{192, 168, 0, 3};
    ip4 = std::array<size_t, 4>{192, 168, 0, 4};
    ip5 = std::array<size_t, 4>{192, 168, 0, 5};

    tree.insert(ip1);
    tree.insert(ip2);
    tree.insert(ip3);
    tree.insert(ip4);
  }

  void TearDown() {}
};

TEST_F(TrieFixture, KeyInsertion) {
  // Assert
  auto root = tree.root();
  EXPECT_FALSE(root.children_[192] == nullptr);
  EXPECT_FALSE(root.children_[192]->children_[168] == nullptr);
  EXPECT_FALSE(root.children_[192]->children_[168]->children_[0] == nullptr);
  EXPECT_FALSE(
      root.children_[192]->children_[168]->children_[0]->children_[1] ==
      nullptr);
  EXPECT_TRUE(root.children_[192]->children_[168]->children_[0]->children_[5] ==
              nullptr);
}

TEST_F(TrieFixture, KeySearch) {
  EXPECT_TRUE(tree.search(ip1));
  EXPECT_FALSE(tree.search(ip5));
}

TEST_F(TrieFixture, KeyPrefix) {
  int* prefix = new int[2]{192, 168};
  EXPECT_TRUE(tree.isPrefix(prefix, 2));
  int* nePrefix = new int[2]{192, 100};
  EXPECT_FALSE(tree.isPrefix(nePrefix, 2));

  delete[] prefix;
  delete[] nePrefix;
}
}  // namespace dsa
