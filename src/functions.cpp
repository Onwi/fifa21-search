#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include "../include/trie.h"
#include "../include/player.h"
using namespace std;

#define ESPACO 40

// ask which search user wants do
// 2.1 return 1 for search on players name
// 2.2 return 2 for search on user reviews
// 2.3 return 3 for search on best players by position
// 2.4 return 4 for search on tags 
int askSearchType(string *argument){
    string str, type;

    cout << "$ ";
    getline(cin, str);

    int i =0;
    while(str[i] != ' '){
        i++;
    }
    type = str.substr(0,i);

    if(type == "player"){
        (*argument) = str.substr(i+1);
        return 1;
    }else if(type == "user"){
        (*argument) = str.substr(i+1);
        return 2;
    }else if(type == "top10"){
        (*argument) = str.substr(i+1);
        return 3;
    }else if(type == "tags"){
        (*argument) = str.substr(i+1);
        return 4;
    }else return -1;
}

void showinfos(list <TrieNode*> *lista, HashTable *table){
	std::list <TrieNode*>::iterator it;
	cout << "sofifa_id" << setw(ESPACO) << "name" << setw(ESPACO) << "positions" << setw(ESPACO) << "rating" << setw(ESPACO) << "count\n";
	for(it = (*lista).begin(); it!=(*lista).end(); it++){
		Info aux = (*table).search((*it)->playerID);
		cout << (*it)->playerID << setw(ESPACO) << (*it)->playerName << setw(ESPACO) 
             << (*it)->positions << setw(ESPACO) << aux.average(aux.reviews, aux.rating) << setw(ESPACO) << aux.reviews << endl;
	} 
}
