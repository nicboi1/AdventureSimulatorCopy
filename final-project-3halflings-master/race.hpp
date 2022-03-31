#ifndef __RACE_HPP__
#define __RACE_HPP__

#include <string>

using namespace std;

class Race{
	protected:
	string name="";
	int numID=0;
	public:
	Race(){}
	virtual ~Race(){}
	virtual int getID(){return numID;}
	virtual string getName(){return name;}

};
class Elf : public Race{
public:
  Elf():Race(){
        name="Elf";
        numID=1;
  }
};
class Dwarf : public Race{
public:
  Dwarf():Race(){
        name="Dwarf";
        numID=2;
  }
};
class Human : public Race{
public:
  Human():Race(){
        name="Human";
        numID=3;
  }
};
class Halfling : public Race{
public:
  Halfling():Race(){
        name="Halfling";
        numID=4;
  }
};

















//combat
//	//TODO combat loop
//
//	int monsterDam
//	int monsterRoll
//	while(player isnt dead)
//			make a monster
//				if(boss time)	
//					make a boss
//				else
//					make a normal monster
//
//				set monster/boss damage and roll mod = current + increment
//
//
//				monster -> increase its roll mod and damage
//				
//				monster introduction
//
//				//TODO fight loop
//				while(the monster and player are alive)
//					
//					display monster with current hp and damage
//
//					accuarcy rolls for monster and player
//
//					if( player lost roll)
//						option to reroll
//
//					compare accuracy rolls
//
//					if(palyer won roll)
//						roll for damage
//						add damMod to damage roll
//						monster loses hp
//					else
//						player loses hp
//						
//
//				if(the monster we fought was a boss)
//					increment monsterDam and monsterRoll	



//int choice = 0;
//cout<ask player for choice>
//cin>> choice
//


































#endif
