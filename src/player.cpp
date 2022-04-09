#include "../include/player.h"

unsigned int hashing(unsigned int x, int size){
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x%size;
}

bool compare_id(Info a, int id){
	if(a.playerID == id) return true;
	else return false;
}

float Info::average(int reviews, float rating){
	return (rating/reviews);
}

HashTable::HashTable(int t_size){
	this->size = t_size;	
	table = new std::list<Info>[size];
}

Info HashTable::search(int id){
	Info fakeInfo(-1,-1);

	int index = hashing(id, this->size);
	std::list <Info>::iterator i;

	for(i = table[index].begin(); i != table[index].end(); i++){
		if(compare_id(*i, id)) return *i;
	}
	// if not on table throw fake data, which will never be on table
	return fakeInfo;
}

//
void HashTable::inc_rr(Info p_info){
	int index = hashing(p_info.playerID, this->size);
	std::list <Info>::iterator i;

	for(i = table[index].begin(); i != table[index].end(); i++){
		if(compare_id(*i, p_info.playerID)){
			i->rating += p_info.rating;
			i->reviews++;
		}
	}
}

void HashTable::insert(Info p_info){
	Info aux = HashTable::search(p_info.playerID);
	// if player not on table
	if(aux.playerID != p_info.playerID){
		// insert on table
		int index = hashing(p_info.playerID, this->size);
		table[index].push_back(p_info);
	}else{
		// else just increment rating and reviews
		inc_rr(p_info);
	}
}
