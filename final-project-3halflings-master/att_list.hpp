#ifndef __ATT_LIST_HPP__
#define __ATT_LIST_HPP__

#include <vector>
#include "attribute.hpp"
using namespace std;

class att_list{


private:

	vector<att*> myAttList;
		


public:

	att_list() {}


	~att_list(){

		for(int i = 0; i < myAttList.size(); ++i)
			delete myAttList.at(i);

	}


	int getSize(){ return myAttList.size(); }

	void addAtt(int num){

		if(num == 1){
			att_elf* newElf = new att_elf();
			myAttList.push_back(newElf);
		}	

		else if(num == 2){
			att_dwarf* newDwarf = new att_dwarf();
			myAttList.push_back(newDwarf);
		}
		else if(num == 3){
			att_human* newHum = new att_human();
			myAttList.push_back(newHum);
		}
		else if(num == 4){
			att_halfling* newHalf = new att_halfling();
			myAttList.push_back(newHalf);
		}
		else{
			cout<<"DEV NOTE: UNEXPECTED INPUT"<<endl;
		}
	}


	void removeAtt(int num){

		for(int i = 0; i < myAttList.size(); ++i){

			if(myAttList.at(i)->getID()==num){
				myAttList.erase(myAttList.begin()+i);
			}

		}

	}

	
	int getTotalRollMod(){

		int total = 0;
		
		for(int i = 0; i < myAttList.size(); ++i){
			
			total = total + myAttList.at(i)->getRollMod();

		}
		
		return total;
	}

	
	//logic: returns the num of rerolls available to a player
	int getTotalReroll(){

		int total = 0;

		for(int i = 0; i < myAttList.size(); ++i){

			if(myAttList.at(i)->getReroll() == true)
				++total;
		
		}

		return total;

	}

	
	int getTotalDamMod(){

		int total = 0;

		for(int i = 0; i <myAttList.size(); ++i){

			total = total + myAttList.at(i)->getDamMod();

		}

		return total;

	}

	
	vector<int> getIDS(){

		vector<int> toReturn;
	
		for(int i = 0; i < myAttList.size(); ++i){

			toReturn.push_back(myAttList.at(i)->getID());
		
		}
	
	}
	


};












































#endif
