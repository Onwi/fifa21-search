#include <iostream>
#include "../include/trie.h"
#include "../include/player.h"
using namespace std;

int askSearchType(std::string *argument);
void showinfos(list <TrieNode*> *lista, HashTable *table);
void addNamePos(string name, string pos, Info *node);
