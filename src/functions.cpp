#include <iostream>
#include <string>
using namespace std;

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
        (*argument) = str.substr(i);
        return 1;
    }else if(type == "user"){
        (*argument) = str.substr(i);
        return 2;
    }else if(type == "top10"){
        (*argument) = str.substr(i);
        return 3;
    }else if(type == "tags"){
        (*argument) = str.substr(i);
        return 4;
    }else return -1;
}
