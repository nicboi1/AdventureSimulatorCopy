#ifndef _TITLE_HPP_
#define _TITLE_HPP_

#include <string>

class title {

private:
int id;
std::string title_name;
int hp_modifier;
int roll_modifier; 

public:

title(int id) : id(id) {
    stats_init(id);
}

void stats_init(int id) {
    switch (this->id) {

        case 1:
            this->title_name = "Bard";
            this->hp_modifier = -15;
            this->roll_modifier = 5;
            break;
        case 2:
            this->title_name = "Ranger";
            this->hp_modifier = 2;
            this->roll_modifier = 0;
            break;
        case 3:
            this->title_name = "Wizard";
            this->hp_modifier = -5;
            this->roll_modifier = 2;
            break;
        case 4:
            this->title_name = "Rogue";
            this->hp_modifier = -8;
            this->roll_modifier = 3;
            break;
        case 5:
            this->title_name = "Paladin";
            this->hp_modifier = 8;
            this->roll_modifier = -2;
            break;
    }
}


std::string getTitle() const { return this->title_name; }
int getHpMod() const { return this->hp_modifier; }
int getRollMod() const { return this->roll_modifier; }

};




#endif