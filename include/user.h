#ifndef _USER_H
#define _USER_H

#include <string>
#include <list>

#include "player.h"

using namespace std;

#define SIZE 200

class User{
public:
	int userID;
	list <Info> revisados;

	User(int id, Info i){
		this->userID = id;
		this->revisados.push_back(i);
	}
	void addInfo(Info inf){
		this->revisados.push_back(inf);
	}
};

class HashUser{
	int size;
	std::list<User> *table;

public:
	HashUser(int t_size);
	
	void insertuser(User u, Info i);
	User *searchuser(int user_id);
};

#endif // _USER_H
