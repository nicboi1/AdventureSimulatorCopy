#ifndef _MONSTER_HPP_
#define _MONSTER_HPP_

#include <string>



// base product, defines interface common to all products for client use
class Monster 
{

public:

    ~Monster(){ }
    
    Monster(int h, int d, int r) : health(h), damage(d), roll_mod(r) {}

    std::string getName() const { return this->name; }

    std::string getIntro() const { return this->introduction; }

    int getDamage() const { return this->damage; }

    int getHealth() const { return this->health; }

    int getRollMod() const { return this->roll_mod; }

    void setIntro(std::string s) {
        this->introduction = s;
    }

    void setName(std::string s) {
        this->name = s;
    }

    // minimum damage is constrained to 1
    void changeDamage(int d) {
        this->damage = (this->damage+d <= 0) ? 1 : this->damage+d;
    } 

    // designed to take a positive number to subtract from current health
    void damageHealth(int d) {
        this->health = (this->health-d <= 0) ? 0 : this->health-d;
    } 
    
    // minimum roll mod is 0
    void changeRollMod(int d) { 
        this->roll_mod = (this->roll_mod+d <= 0) ? 0 : this->roll_mod+d;
        
    }  

    bool isAlive() {
        return (this->health==0)? false : true;
    }

    void attack(Monster* m) {
        m->damageHealth(this->getDamage());
    }


private:

    std::string name;
    std::string introduction;
    int damage;
    int health;
    int roll_mod;
 

};



#endif
