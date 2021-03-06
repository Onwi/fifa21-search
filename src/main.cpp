#include <functional>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>

#include "../include/player.h"
#include "../include/trie.h"
#include "../include/parser.hpp"
#include "../include/functions.h"
#include "../include/user.h"

#define USERS_SIZE 2000
#define TABLE_SIZE 2000
using namespace aria::csv;

int main(int argc, char *argv[]){
	std::ifstream rr("../dataset/minirating.csv");
	CsvParser parser(rr);
	int le_id, colF=0, id_rating;
   	bool rowF = false;	
	float le_rating;	
	std::list <Trie*> lista;
	Info *hnode;
	HashUser usersTable(USERS_SIZE);

	//hash table for rating and reviews
	HashTable hashRR(TABLE_SIZE);
	// read player ID and rating and put on table
	for (auto& row : parser) {
    	for (auto& field : row) {
      		//std::cout << field << " | ";
			// ignore first column 
			if(rowF){
				if(colF == 0) id_rating = std::stoi(field); //user id
				if(colF == 1) le_id = std::stoi(field); //player id
				if(colF == 2) le_rating = std::stof(field); 
				colF++;
			}
    	}
    	//std::cout << std::endl;
		colF=0;
		rowF=true;
		Info le_rr(le_id, le_rating);
		hashRR.insert(le_rr);
		// User stuff
		User usr(id_rating, le_rr);
		usersTable.insertuser(usr, le_rr);
  	}
	rr.close();
	
	std::ifstream rname("../dataset/players.csv");
	CsvParser parserplyer(rname);
	// Trie for players names	
	Trie* trieNode = new Trie();
	// read player name, ID and position and store on trie
	rowF=false;
	colF=0;
	std::string p_name, pos;
	for (auto& row : parserplyer) {
		for (auto& field : row) {
			// ignore first row 
			if(rowF){
				if(colF ==0) le_id= std::stoi(field);
				if(colF ==1) p_name = field;
				if(colF ==2) pos = field;
				colF++;
			}
    	}
		colF=0;
		rowF=true;
		// insert node on trie*/
		trieNode->insert(p_name, le_id, pos);
	}
	rname.close();
	
	// gotta parse players.csv again cause I suck at pointers
	std::ifstream hashnames("../dataset/players.csv");
	CsvParser parserhashname(hashnames);
	
	rowF=false;
	colF=0;
	for (auto& row : parserhashname) {
		for (auto& field : row) {
			// ignore first row 
			if(rowF){
				if(colF ==0) le_id= std::stoi(field);
				if(colF ==1) p_name = field;
				if(colF ==2) pos = field;
				colF++;
			}
    	}
		colF=0;
		rowF=true;
		hnode = hashRR.search(le_id);
		addNamePos(p_name, pos, hnode);
	}
	hashnames.close();

	Trie* prefix;
	std::string arguments;
	bool sair = false;
	int userid;
	User *newnode;
	do{
		switch(askSearchType(&arguments)){
			case 1:{
					prefix = trieNode->search(arguments);
					if(!prefix){ 
						std::cout << "nao ha nome com esse prefixo\n";
						break;
					}
					addPlayers(prefix, 0, &lista);
					system("clear");
					showinfos(&lista, &hashRR);
					lista.clear();
					break;
				}
			case 2: userid = std::stoi(arguments);
					newnode = usersTable.searchuser(userid);
					showUser(newnode, &hashRR);
					break;
			case 3:
			case 4:
			default: sair = true;	
		}
	}while(!sair);
		
	return 0;
}
