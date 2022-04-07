#include <iostream>
#include <fstream>

#include "../include/player.h"
#include "../include/trie.h"

int main(int argc, char *argv[]){
	struct TrieNode *node;	
	
	std::string name1, name2, name3;

	name1 = "Leo Messi";
	name2 = "Neymar";
	name3 = "Cristiano Ronaldo";
	
	insert(node, name1, 1000);
	insert(node, name1, 1001);
	insert(node, name1, 1002);

	struct TrieNode *pesquisa;

	pesquisa = search(node, "Leo");

	std::cout << pesquisa->playerID;

	return 0;
}
