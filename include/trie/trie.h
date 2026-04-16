#ifndef INCLUDE_TRIE_TRIE_H_
#define INCLUDE_TRIE_TRIE_H_

#include <array>
#include <iostream>

namespace dsa {
class Trie {
  using Index = size_t;
  using Key = const std::array<Index, 4>&;

 public:
  class TrieNode {
   public:
    TrieNode() {
      for (int i = 0; i < 256; i++) {
        this->children_[i] = nullptr;
      }
    };
    TrieNode(Index value) : value_(value) {
      for (int i = 0; i < 256; i++) {
        this->children_[i] = nullptr;
      }
    };

    void print() {
      if (isLeaf_) {
        std::cout << value_ << "\n";
      } else {
        for (auto child : children_) {
          if (child == nullptr) continue;
          std::cout << value_ << "\n";
          child->print();
        }
      }
    };

    bool isLeaf_ = false;
    std::array<TrieNode*, 256> children_;

   private:
    int value_ = -1;
  };

  Trie() : root_(TrieNode()) {};
  ~Trie() { deleteNode(&root_); }

  TrieNode const root() { return root_; }

  void insert(Key key) {
    TrieNode* curr = &root_;
    for (auto k : key) {
      if (curr->children_[k] == nullptr) {
        curr->children_[k] = new TrieNode(k);
      }

      curr = curr->children_[k];
    }

    curr->isLeaf_ = true;
  };

  bool search(Key key) {
    TrieNode* curr = &root_;
    for (auto k : key) {
      if (curr->children_[k] == nullptr) continue;
      if (curr->children_[k]->isLeaf_) {
        return true;
      }

      curr = curr->children_[k];
    }
    return false;
  }

  bool isPrefix(int key[], size_t len) {
    TrieNode* curr = &root_;
    for (size_t i = 0; i < len; i++) {
      auto k = key[i];
      if (curr->children_[k] == nullptr) return false;
      if (curr->children_[k]->isLeaf_) {
        return true;
      }

      curr = curr->children_[k];
    }
    return true;
  }

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
