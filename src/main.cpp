#include <functional>
#include <iostream>
#include <fstream>
#include <list>

#include "../include/player.h"
#include "../include/trie.h"

int main(int argc, char *argv[]){
	std::string name1, name2, name3, nam4, name4, name6, name7;
	std::list <struct TrieNode*> lista;
	struct TrieNode *pesquisa= getNode();

	// test strings	
	name1 = "Leo Messi";
	name4 = "Leo M";
	name6 = "Leonardo";
	name2 = "Neymar";
	name3 = "Cristiano Ronaldo";
	nam4 = "Leo";
	
	insert(pesquisa, name1, 1000, "cw, mei");
	insert(pesquisa, name2, 1001, "ata, pte");
	insert(pesquisa, name3, 1002, "ata, ptd");
	insert(pesquisa, name4, 1004, "cw, mei");
	insert(pesquisa, name6, 1050, "ata, pe");
	
	struct TrieNode *node;		

	node = search(pesquisa, nam4);
	
	addPlayers(node, 0, &lista);	

	std::list<struct TrieNode*>::iterator i;
	std::cout << lista.size() << std::endl;
	for(i = lista.begin(); i!=lista.end(); i++){
		std::cout << (*i)->playerID << (*i)->positions << std::endl;
	}	
	
	return 0;
}
