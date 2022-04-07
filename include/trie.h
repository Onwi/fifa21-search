#ifndef	_TRIE_H
#define _TRIE_H

#include <cstdio>
#include <cstdlib>
#include <string>

const int ALPHABET_SIZE = 27;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
	int playerID; 
    // isEndOfWord is true if the node represents end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void);

void insert(struct TrieNode *root, std::string key, int id);

// search for a @key prefix name on trie
struct TrieNode *search(struct TrieNode *root, std::string key);

#endif

