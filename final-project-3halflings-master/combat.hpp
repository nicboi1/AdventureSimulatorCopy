#ifndef COMABT_HPP
#define COMBAT_HPP

#include "character.hpp"
#include "monster.hpp"
#include "monster_factory.hpp"
#include <iostream>
#include <stdlib.h>
#include <random>
#include <limits>

using namespace std; 
int Combat(character* myChar){
	int damMod=0;
	int rollMod=0;
	int monCount=0;
	int playerAcc=0;
	int monAcc=0;
	int BaseDmg=0;
	int choice=0;
	int chaRR=myChar->getRerollCount();
	int pdmg=0;
	int mdmg=0;
	int score=0;
	int playerHP=myChar->getHP();

	default_random_engine generator;
	uniform_int_distribution<int> D6(1,6);
	uniform_int_distribution<int> D20(1,20);
	uniform_int_distribution<int> D4(1,4);
	uniform_int_distribution<int> D10(1,10);

	MonsterFactory monfact;
	BossMonsterFactory bmonfact;
	Monster* mon=nullptr;

	//combat loop
	while(playerHP>0){
		
	
		//checking to see if boss time or normal monst; respective call initiates
		if(monCount==3){
			cout<<"A new foe has appeared!! Be careful this one is stronger than most..."<<endl<<endl;
        		mon = bmonfact.makeMonster();
			monCount=-1;
		// bmon			
		}else{
			cout<<"A new foe appears!!"<<endl<<endl;
			mon= monfact.makeMonster();	
			
		}

		//update values accordingly
		mon->changeDamage(mon->getDamage()+damMod);
                mon->changeRollMod(mon->getRollMod()+rollMod);
		
		
		//monster greets player
		//cout<<"A new foe appears!!"<<endl<<endl<<
		cout<<mon->getName()<<endl<<endl<<
		'"'<<mon->getIntro()<<'"'<<endl<<endl;



			//fight loop with generated monster
			while(mon->getHealth()>0 && playerHP>0){
	
				//display dmg n health
				cout<<mon->getName()<<" currently has "<<mon->getHealth()<<" HP."<<endl<<
				mon->getName()<<" will deal "<< mon->getDamage()<<" if they land a hit!"<<
				endl<<endl;

				cout<<"Against the foe, you still carry "<<playerHP<<" HP."<<endl<<
				"You wield, "<<myChar->getDamageMod()+1<<" - "<<myChar->getDamageMod()+6<<
				endl<<endl;

				//first calculation of player and monster accuracy

				cout<<"*ENTER 'Roll' TO ROLL FOR ACCURACY*"<<endl;
				
				string response;
				getline(cin, response);
				
				if(response.empty()){

					getline(cin, response);

				}
				
					
				while(response != "Roll" && response != "roll"){

				cout<<"Take your time, it is scary afterall :)"<<endl<<
					"*ENTER 'Roll' TO ROLL FOR ACCURACY*"<<endl;
					getline(cin, response);	
					

				}
		
				cout<<endl<<endl;

				playerAcc = myChar -> getRollMod() + D20(generator);
				monAcc = mon -> getRollMod() + D20(generator);
				
				if(playerAcc == monAcc){
					--playerAcc;
				}			

				//check if player lost, and has an available reroll
				if(playerAcc<monAcc && chaRR>0){
					//cout reroll options

					cout<<"It looks like the monster will hit! It rolled a " <<
					monAcc << " while you rolled a " << playerAcc<<'.'<<endl<<
					endl<<"Would you like to use a reroll to try again?"<<endl<<
					"You have "<< chaRR<<" left."<<endl<<
					"(1) Yes"<<endl<<
					"(2) No"<<endl<<
					"*CHOOSE A NUMBER (1-2)*"<<endl;
					
					//string response;
                               		cin>>choice;

        	                       
					while(choice<1 || choice>2){
                                        	if(!choice){
                                                	cout<<"Whoah, didn't quite catch that, try again!"<<endl;
                                                	cin.clear();
                                                	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                                	cin>>choice;
                                        	}
                                        	else{
                                                	cout<<"Whoah, didn't quite catch that, try again!"<<endl;
                                              		cin>>choice;
                                        	}

                               		 }

					cout<<endl<<endl;

					//case player decided to reroll
					if(choice==1){
						chaRR--;
						playerAcc=myChar -> getRollMod() + D20(generator);
				
					}
				
				
				}

				//final comparison of values
				if(playerAcc>monAcc){
					cout<<"You beat the monster's roll by: "<<playerAcc-monAcc<<endl;
					
					pdmg=myChar->getDamageMod()+D6(generator);

					if(pdmg<0)
						pdmg = 0;

					mon->damageHealth(pdmg);
					
					cout<<"You hit the monster for: "<<pdmg<<" !"<<endl;

				}
				
				//lost roll
				else{
					cout<<"The monster beat your roll by: "<<monAcc-playerAcc<<endl;
					
					mdmg=mon->getDamage();
					playerHP-=mdmg;
					
					cout<<"The monster hit you for: "<<mdmg<<" !"<<endl<<endl;
				}
				
				if(mon->isAlive()==false)
					break;
				
				//while loop exits if one has died, otherwise repeats	
			}

			//case the player finished the fight and won
			if(playerHP>0){
				score+=1;
			
				//new att or resAtore hp
				cout<<"Huzzah! "<<mon->getName()<<" is defeated!!" <<endl<<
				"As a reward for your victory would you rather have your lost HP "<<
				"restored or, possibly gain another reroll and some more damage?"<<endl<<
				"Careful however, "<<myChar->getPlayerName()<<" you may lose current "<<
				"attributes in the process!"<<endl<<endl;

				cout<<"(1) Restore HP to full"<<endl<<
				"(2) Gamble for a new attribute"<<endl<<
				"*CHOOSE A NUMBER (1-2)*"<<endl;
				cin>>choice;
		
				while(choice<1 || choice>2){
					if(!choice){
                                                cout<<"Whoah, didn't quite catch that, try again!"<<endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                                cin>>choice;
					}
					else{
						cout<<"Whoah, didn't quite catch that, try again!"<<endl;
						cin>>choice;	
					}
						
                                }
	
				cout<<endl<<endl;

				if(choice == 1){

					playerHP = myChar -> getHP();

				}
				else{

					int choiceGamble = D10(generator);
					if(choiceGamble<=5){

						cout<<"Curses! You lost an attribute :("<<endl;		
						myChar -> remove_att(D4(generator));
					}
					else{

						cout<<"Rejoice, you have gained a new attribute!"<<endl;
						choiceGamble = D4(generator);
						myChar->add_player_att(choiceGamble);
						
					}

				}				
			
				//reset rerollCount
				chaRR = myChar -> getRerollCount();		

				
				//setting increased difficulty
				if(monCount==-1){
					damMod+=2;
					rollMod+=1;
				}
				monCount++;
			}
		if(playerHP>0){
			cout<<"You continue on your journey, are you ready?"<<endl<<endl<<
			"*TYPE 'Ready' WHEN PREPARED*"<<endl;
			string garbo = "";
	
			getline(cin, garbo);
	
			string cont = "";
			getline(cin, cont);

			while(cont != "Ready" && cont != "ready"){

				cout<<"Just take your time then!"<<endl<<
				"*TYPE 'Ready' WHEN PREPARED*"<<endl;
				getline(cin, cont);
			}
			cout<<endl<<endl;
		}
		delete mon;	
		//whole combat loop repeats until player has died 
	} 
	cout<<endl<<endl<<"OOF, YOU HAVE BEEN SLAIN :'("<<endl;
	return score;
}



#endif
