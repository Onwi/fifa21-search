#include <functional>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>

#include "../include/player.h"
#include "../include/trie.h"
#include "../include/parser.hpp"

#define TABLE_SIZE 2000
using namespace aria::csv;

int main(int argc, char *argv[]){
	std::ifstream rr("../dataset/minirating.csv");
	CsvParser parser(rr);
	int le_id, colF=0;
   	bool rowF = false;	
	float le_rating;	
	std::list <TrieNode*> lista;

	//hash table for rating and reviews
	HashTable hashRR(TABLE_SIZE);
	// read player ID and rating and put on table
	for (auto& row : parser) {
    	for (auto& field : row) {
      		//std::cout << field << " | ";
			// ignore first column and first row 
			if(rowF){
				if(colF == 1) le_id = std::stoi(field);
				if(colF == 2) le_rating = std::stof(field); 
				colF++;
			}
    	}
    	//std::cout << std::endl;
		colF=0;
		rowF=true;
		Info le_rr(le_id, le_rating);
		hashRR.insert(le_rr);
  	}
	rr.close();
	
	std::ifstream rname("../dataset/players.csv");
	CsvParser parserplyer(rname);
	// Trie for players names	
	struct TrieNode *names = getNode();
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
		// convert p_name to lower case to work with our 27 alphabet size trie	
		std::for_each(p_name.begin(), p_name.end(), [](char & c){
    		c = ::tolower(c);
		});
		// insert node on trie
		insertTrie(names, p_name, le_id, pos);
  	}
	
		
	return 0;
}
