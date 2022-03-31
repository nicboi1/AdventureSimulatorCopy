#include <iostream>

#include "character.hpp"
#include "combat.hpp"
using namespace std;

int main(){


	character* myChar = new character();
	int score = Combat(myChar);
	
	cout<<endl<<endl<<myChar->getPlayerName()<<" slayed "<<score<<
	" monsters before their journey ended!"<<endl<<endl<<endl;
	delete myChar;


return 0;
}
