/*
 *	Structures to store information of players
 */

#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <list>


// rating and review info
class Info{
public:
	int playerID;
	int reviews = 1;
	float rating;

	Info(int id, float rt){
		this->playerID = id;
		this->rating = rt;
	}

	float average(int reviews, float rating);
};
	
/* Hash table to store average and rating and total of reviews */
class HashTable{
	int size;	
	std::list<Info> *table;

public:
	HashTable(int t_size);

	// search for info on table by player @id
	Info search(int id);
	// insert player info on table 
	void insert(Info p_info);
	// increment review and rating if already on table
	void inc_rr(Info p_info);
};

//compare two ids
bool compare_id(Info a, int id);
// hash function
unsigned int hashing(unsigned int x, int size);

#endif //_PLAYER_H
