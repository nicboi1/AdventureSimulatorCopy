#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__


//main
//	user* myPlayer = new user(); -> user will call the character constructor
//	enterCombat(myPlayer->character);
//	score(myPlayer->character);
//
//

#include <iostream>
#include "race_stats.hpp"
#include "att_list.hpp"
#include "title.hpp"
#include <stdlib.h>
#include <random>
#include <limits>
//combat function: first roll: accuracy:20, second roll: damage:6

using namespace std;

class character {

private:

	string playerName = "";
	int hp = 40;
	int OG_hp;
	int damage_mod = 0;
	int roll_mod = 0;
	int reroll_count = 1;
	race_stats* playerRace;
	title* playerTitle; 

public:
	character(){

		cout<<"Greetings Adventurer!"<<endl<<endl
		<<"My name is Hozal Earthflayer, a humble dwarf, and a fellow adventurer!"<<endl<<endl
		<<"May I ask what your name is?"<<endl
		<<"*ENTER YOUR CHARACTER NAME*"<<endl;
		
		string temp;
		getline(cin, temp);
		cout<<endl;
		
		while(temp == playerName){
			cout<<"Whoah, didn't quite catch that, could you repeat it?"<<endl;
			cin>>temp;
		}

		playerName = temp;

		//above segment obtains the player chosen name for their character
		

		cout<<endl<<"Excellent! pleased to meet you "<<playerName<<endl<<
		"Excuse my ignorance, but my curiousity will not let me be! "<<
		"Would you reveal to me what type of creature you are?"<<endl<<endl;

		int choice=0;

		cout<<
		"(1) A Woodland Elf, from a distant forest"<<endl<<
		"(2) A Mountain Dwarf, from a distant fortress"<<endl<<
		"(3) A Dessert dwelling Human, from a distant kingdom"<<endl<<
		"(4) A Grassland Halfling, from a distant shire"<<endl<<
		"*CHOOSE A NUMBER (1-4)*"<<endl;

		cin>>choice;
		while(choice>4 || choice<1){
			if(!choice){
			cout<<endl<<"Whoah, didn't quite catch that, could you repeat it?"<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cin>>choice;
			}
			else{
			cout<<endl<<"Whoah, didn't quite catch that, could you repeat it?"<<endl;
			cin>>choice;
			}

		}

		playerRace = new race_stats(choice);

		cout<<endl<<"Ahhh, how exotic, a true "<< playerRace -> get_race_name()<< 
		" stands before me!!"<<endl;

		//above segment sets the players race_stat
		choice = 0;
		
		cout<<"Well Master "<<playerRace -> get_race_name() << ", what role do you serve in this Adventure!?"<<endl<<endl<<
		"(1) Bard"<<endl<<
		"(2) Ranger"<<endl<<
		"(3) Wizard"<<endl<<
		"(4) Rogue"<<endl<<
		"(5) Paladin"<<endl<<
		"*CHOOSE A NUMBER (1-5)*"<<endl;

		cin>>choice;
		while(choice>5 || choice<1){

                        if(!choice){
                        cout<<endl<<"Whoah, didn't quite catch that, could you repeat it?"<<endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cin>>choice;
                        }
                        else{
                        cout<<endl<<"Whoah, didn't quite catch that, could you repeat it?"<<endl;
                        cin>>choice;
                        }

                }

		playerTitle = new title(choice);
		

		hp = hp + playerTitle -> getHpMod();
		
		OG_hp = hp;	
		
		roll_mod = playerTitle -> getRollMod() + playerRace -> get_roll_mod();

		damage_mod = playerRace -> get_dam_mod();

		//above segment sets their final stats based on their race and title choices
			


		cout<<endl<<"Well my stars, I've never met a "<<playerRace->get_race_name()<<" "<< 
		playerTitle -> getTitle()<<" before!!"<<endl<<
		"Alas my friend, I must embark on my monster slaying quest, same as you! "<<
		"Farewell, and good luck "<<playerName<<endl<<endl;



		
	}
	~character(){
		delete playerRace;
		delete playerTitle;
	}

	int reduce_hp(int amount){
		hp = hp - amount;
		return hp;
	}

	void restore_hp(){
		hp = OG_hp;
	}


	void add_player_att(int num){
		
		playerRace -> addtoList(num);

		roll_mod = playerTitle -> getRollMod() + playerRace -> get_roll_mod();
                damage_mod = playerRace -> get_dam_mod();
		++reroll_count;	
	
	}

	
	void remove_att(int num){
		
		if(reroll_count == 0)
			return;

		playerRace -> removeAtt(num);
		
		roll_mod = playerTitle -> getRollMod() + playerRace -> get_roll_mod(); 
                damage_mod = playerRace -> get_dam_mod();
		--reroll_count;
			
	}

	
	int getRerollCount(){ return reroll_count; }

	int getDamageMod(){ return damage_mod; }

	int getRollMod(){ return roll_mod; }

	string getPlayerName(){ return playerName; }

	int getHP(){ return hp; }

	vector<int> getIDS(){ return playerRace->getIDS(); }

};






#endif
