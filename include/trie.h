#ifndef	_TRIE_H
#define _TRIE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>

const int ALPHABET_SIZE = 27; //26 letters and space

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
	int playerID;
	std::string positions;	
    // isEndOfWord is true if the node represents end of a word
    bool isPlayerName;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void);

void insert(struct TrieNode *root, std::string key, int id, std::string positions);

// search for a @key prefix name on trie
struct TrieNode *search(struct TrieNode *root, std::string key);

// check if current node is a player's name
bool isName(struct TrieNode* root);

//add a node to list if node is a player's name
void addPlayers(struct TrieNode* root, int level, std::list <struct TrieNode*> *lista);

#endif

