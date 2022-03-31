#ifndef _MONSTER_FACTORY_HPP_
#define _MONSTER_FACTORY_HPP_

#include "monster.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

const int BASE_HEALTH = 10;
const int BASE_DAMAGE = 4;
const int BASE_ROLLMOD = 0;
const int BOSS_HEALTH = 20;
const int BOSS_DAMAGE = 8;

std::vector<std::string> intro = {  
                                        "Sometimes human places, create inhuman monsters.",
                                        "If you gaze long enough into an abyss, the abyss will gaze back into you",
                                        "It is the first day of November and so, today, someone will die.",
                                        "I will rip you flesh from bone",
                                        "Nothing is evil which is according to nature.",
                                        "All spirits are enslaved which serve things evil",
                                        "Death is the only adventure you have left!",
                                        "You poor, simple fools. Thinking you could defeat me. Me! The mistress of all evil!",
                                        "Normal people have no idea how beautiful the darkness is.",
                                        "Conscience is the window of our spirit, evil is the curtain",             
                                        };




// define methods to create all related products
// A concrete factory is used as main factory since implementation is simple with few changes
class Factory 
{
public:
       virtual Monster* makeMonster() const = 0;

};


class MonsterFactory : public Factory
{
public:

    // init intro, and name for base monster
    virtual Monster* makeMonster() const { 
        Monster* mon = new Monster(BASE_HEALTH, BASE_DAMAGE, BASE_ROLLMOD);
        srand(time(0));

        int ix = rand() % intro.size();
        mon->setIntro(intro.at(ix));    

        ix = rand() % names.size();
        int inx = rand() % titles.size();
        std::string s = names.at(ix) + " the " + titles.at(inx);
        
        mon->setName(s);
          
        return mon;
    }

private:
    std::vector<std::string> names = {      
                                        "Bobo", "Gulon", "Moogie", "Lahk", "Yilu", 
                                        "Ezmel", "Cerys", "Tont", "Akiro", "Fin"
                                        };

    std::vector<std::string> titles = {  
                                        "Orc", "Cyclops", "Gargoyle", "Goblin", "Werewolf", "Zombie", 
                                        "Martian", "Ghoul", "Grimlock", "Gnoll" 
                                        };


};

// concrete factory 
class BossMonsterFactory : public Factory 
{
public:
    // init intro and name for boss monster 
    Monster* makeMonster() const { 
        Monster* mon = new Monster(BOSS_HEALTH, BOSS_DAMAGE, BASE_ROLLMOD);
        srand(time(0));

        int ix = rand() % intro.size();
        mon->setIntro(intro.at(ix));    

        ix = rand() % boss_names.size();
        int inx = rand() % boss_titles.size();
        std::string s = boss_names.at(ix) + " the " + boss_titles.at(inx);
        
        mon->setName(s);
          
        return mon;
    }
private:
    std::vector<std::string> boss_names = {    
                                            "Draco", "Khitun", "Juran", "Bane", "Onix", 
                                            "Inion", "Dremal", "Azriel", "Nifis", "Vindio", 
                                            };

    std::vector<std::string> boss_titles = {  
                                            "Defilier", "Nightmare Dragon", "Lord of the Dead", "Tormentor", "Wandering Wizard", "Vengeful Spirit", 
                                            "Wraith", "Man-Eating Spider", "Keeper of Lost Souls", "Two-Headed Basilisk"
                                            };

};




#endif 
