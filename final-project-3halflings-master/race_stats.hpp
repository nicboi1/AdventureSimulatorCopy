#ifndef __RS_HPP__
#define __RS_HPP__

#include "att_list.hpp"
#include "race.hpp"

class race_stats{


private:
	
	Race* player_race;
	att_list* player_atts;


	//during combat, will need a temp copy of the att_list which can have the att objects removed as the player activates them
public:
	~race_stats(){
		delete player_race;
		delete player_atts;
	}
	race_stats(int num){

		if(num == 1){
			player_race = new Elf();
			player_atts = new att_list();
			player_atts->addAtt(num);

		}

		else if(num == 2){
		
			player_race = new Dwarf();
                        player_atts = new att_list();
                        player_atts->addAtt(num);


		}

		else if(num == 3){

			player_race = new Human();
                        player_atts = new att_list();
                        player_atts->addAtt(num);

		}

		else if(num == 4){

			player_race = new Halfling();
                        player_atts = new att_list();
                        player_atts->addAtt(num);

		}

		else{

			cout<< "DEV NOTE, UNEXPECTED NUM"<<endl;		

		}

	}


	int get_roll_mod() {

		return player_atts->getTotalRollMod();

	}


	int get_dam_mod() {

		return player_atts->getTotalDamMod();

	}

	
	int get_total_reroll(){

		return player_atts->getTotalReroll();

	}

	
	string get_race_name(){

		return player_race->getName();

	}


	int get_race_id(){

		return player_race->getID();
	
	}

	void addtoList(int num){

		player_atts->addAtt(num);

	}

	void removeAtt(int num){

		player_atts->removeAtt(num);

	}


	vector<int> getIDS(){


		return player_atts->getIDS();

	}

};














#endif
