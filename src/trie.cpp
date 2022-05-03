#include "../include/trie.h"
#include <iostream>
#include <string>

using namespace std;

// inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void Trie::insert(string key, int id, string positions){
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++){
        if (curr->character[key[i]] == nullptr) {
            curr->character[key[i]] = new Trie();
        }
        curr = curr->character[key[i]];
    }
    curr->isLeaf = true;
    curr->playerID = id;
    curr->positions = positions;
    curr->playerName = key;
}
 
// search for a @key prefix name on trie
// return NULL if there's no name with prefix
// else return node where prefix ends
Trie* Trie::search(string key){
    if (this == nullptr) {
        return NULL;
    }
 
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++){
        // go to the next node
        curr = curr->character[key[i]];
 
        if (curr == nullptr) {
            return NULL;
        }
    }
 
    return curr;
}

// check if current node is a player's name 
bool isName(Trie* root){
    return root->isLeaf != false;
}

void addPlayers(Trie* root, int level, list <Trie*> *lista){
    if (isName(root)){
   		(*lista).push_back(root); 
	}
	 
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (root->character[i]){
            addPlayers(root->character[i], level + 1, lista);
        }
    }
}