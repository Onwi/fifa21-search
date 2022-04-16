#include "../include/user.h"
#include "../include/player.h"

HashUser::HashUser(int t_size){
	this->size = t_size;
	table = new std::list<User>[size];
}

User* HashUser::searchuser(int user_id){
	int index = hashing(user_id, this->size);
	std::list <User>::iterator i;
	
	for(i = table[index].begin(); i != table[index].end(); i++){
		if((*i).userID == user_id)
			return &(*i);
	}
	return NULL;
}

void HashUser::insertuser(User u, Info inf){
	User *aux = HashUser::searchuser(u.userID);
	// if user not on table	
	if(!aux){
		// insert
		int index = hashing(u.userID, this->size);
		table[index].push_back(u);
	}else{
	// if user already on table, insert info on its list	
		(*aux).addInfo(inf);
	}
}


