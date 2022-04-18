#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <iostream>
#include "../include/trie.h"
#include "../include/player.h"
#include "../include/user.h"
using namespace std;

int askSearchType(std::string *argument);
void showinfos(list <TrieNode*> *lista, HashTable *table);
void addNamePos(string name, string pos, Info *node);
void printUser(float avg, Info *inf);
void showUser(User *u, HashTable *h);

#endif
