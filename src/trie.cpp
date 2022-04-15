#include "../include/trie.h"
#include <iostream>
#include <string>

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void){
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isPlayerName = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

// inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insertTrie(struct TrieNode *root, std::string key, int id, std::string positions){
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
	pCrawl->isPlayerName = true;
	pCrawl->playerID = id;
	pCrawl->positions = positions;
	pCrawl->playerName = key;
}


// search for a @key prefix name on trie
// return NULL if there's no name with prefix
// else return node where prefix ends
struct TrieNode *searchTrie(struct TrieNode *root, std::string key){
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return NULL;
 
        pCrawl = pCrawl->children[index];
    }
 
    return pCrawl;
}

// check if current node is a player's name 
bool isName(struct TrieNode* root){
    return root->isPlayerName != false;
}

void addPlayers(struct TrieNode* root, int level, std::list <struct TrieNode*> *lista){
    if (isName(root)){
   		(*lista).push_back(root); 
	}
	 
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (root->children[i]){
            addPlayers(root->children[i], level + 1, lista);
        }
    }
}
