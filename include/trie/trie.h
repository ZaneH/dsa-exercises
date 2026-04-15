#ifndef INCLUDE_TRIE_TRIE_H_
#define INCLUDE_TRIE_TRIE_H_

#include <array>
#include <iostream>

namespace dsa {
class Trie {
  using Index = size_t;

 public:
  class TrieNode {
   public:
    TrieNode() : isLeaf_(false) {
      for (int i = 0; i < 256; i++) {
        this->children_[i] = nullptr;
      }
    };
    TrieNode(Index value) : value_(value) {
      for (int i = 0; i < 256; i++) {
        this->children_[i] = nullptr;
      }
    };

    std::array<TrieNode*, 256> children_;

    void print() {
      if (isLeaf_) {
        std::cerr << value_ << "\n";
      } else {
        for (auto child : children_) {
          if (child == nullptr) continue;
          std::cerr << value_ << "\n";
          child->print();
        }
      }
    };

    bool isLeaf_ = false;

   private:
    int value_ = -1;
  };

  Trie() : root_(TrieNode()) {};
  ~Trie() { deleteNode(&root_); }

  void insert(const std::array<Index, 4>& key) {
    TrieNode* curr = &root_;
    for (Index k : key) {
      if (curr->children_[k] == nullptr) {
        curr->children_[k] = new TrieNode(k);
      }

      curr = curr->children_[k];
    }

    curr->isLeaf_ = true;
  };

  void print() {
    TrieNode curr = root_;
    for (auto child : curr.children_) {
      if (child == nullptr) continue;
      child->print();
    }
  }

 private:
  TrieNode root_;

  void deleteNode(TrieNode* node) {
    for (auto child : node->children_) {
      if (child == nullptr) continue;
      deleteNode(child);
      delete child;
    }
  }
};
}  // namespace dsa

#endif  // INCLUDE_TRIE_TRIE_H_
