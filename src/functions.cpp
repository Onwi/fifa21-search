#include <iostream>
#include <string>
using namespace std;

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

    return 0;
}