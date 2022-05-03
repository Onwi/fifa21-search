#ifndef	_TRIE_H
#define _TRIE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
using namespace std;

const int ALPHABET_SIZE = 128; //26 letters and space
// A class to store a Trie node
class Trie{
public:
    bool isLeaf;
    int playerID;
    string positions;
    string playerName;
    Trie* character[ALPHABET_SIZE];
 
    // Constructor
    Trie(){
        this->isLeaf = false;
 
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            this->character[i] = nullptr;
        }
    }
 
    void insert(string key, int id, string positions);
    Trie* search(string key);
};

// check if current node is a player's name
bool isName(Trie* root);
//add a node to list if node is a player's name
void addPlayers(Trie* root, int level, list <Trie*> *lista);

#endif