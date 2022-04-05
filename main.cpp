#include <iostream>
#include <fstream>

#include "player.h"

int main(int argc, char *argv[]){
	
	Info p1(256417, 1.5);
	Info p2(13425, 4.3);
	Info p3(134562, 5);
	Info p4(246417, 3.6);
	Info p5(106417, 2.9);
	
	Info p6(256417, 4.5);
	Info p7(13425, 2);
	Info p8(134562, 15);
	Info p9(246417, 7);
	Info p10(106417, 2.9);
	HashTable tab(50);

	tab.insert(p1);
	tab.insert(p2);
	tab.insert(p3);
	tab.insert(p4);
	tab.insert(p5);
	tab.insert(p6);
	tab.insert(p7);
	tab.insert(p8);
	tab.insert(p9);
	tab.insert(p10);

	Info teste = tab.search(p1.playerID);

	std::cout << teste.playerID << " " << teste.reviews <<" "<< teste.average(teste.reviews, teste.rating) << " " << std::endl;

	teste = tab.search(p2.playerID);
	std::cout << teste.playerID << " " << teste.reviews <<" "<< teste.average(teste.reviews, teste.rating) << " " << std::endl;

	teste = tab.search(p3.playerID);
	std::cout << teste.playerID << " " << teste.reviews <<" "<< teste.average(teste.reviews, teste.rating) << " " << std::endl;

	teste = tab.search(p4.playerID);
	std::cout << teste.playerID << " " << teste.reviews <<" "<< teste.average(teste.reviews, teste.rating) << " " << std::endl;

	teste = tab.search(p5.playerID);
	std::cout << teste.playerID << " " << teste.reviews <<" "<< teste.average(teste.reviews, teste.rating) << " " << std::endl;

	return 0;
}
