# Trie

A trie (a.k.a. Prefix Tree) is a data structure used to index data efficiently. Examples of data that might benefit from a trie include words
(trie's are often used in autocomplete implementations) or IP address lookup tables (by storing octets as a node in the
trie). Data that utilizes a prefix search will often be stored in a trie. A trie has time of O(n) and space O(n).

## Terminology

- Node: A vertex within the trie data structure. Nodes can have ≥ 0 children. Nodes store the reference to their
  children.
- Root Node: The beginning of the trie. There is exactly one root node in a trie. All nodes are descendants of the root
  node.
- Leaf: A node without children. These represent indexed values. Their key is constructed by traversing up the trie.
- Key: An identifier for a node.

## Invariants

- Number of Root Nodes == 1

## Resources

- https://www.geeksforgeeks.org/dsa/trie-insert-and-search/
