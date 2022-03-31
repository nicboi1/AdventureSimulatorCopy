#include "monster_factory.hpp"
#include "monster.hpp"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>



int main() {

    srand(time(0));
    int i{0}; 
    int max = 1;

    MonsterFactory factory;
    Monster* monster = factory.makeMonster();
     delete monster;
     monster = nullptr;
	


/*
        int m = rand() % 100;
        MonsterFactory* factory = nullptr;
        factory = (m%2 == 0) ? new MonsterFactory(): new BossMonsterFactory();
        Monster* monster = factory->makeMonster();

        std::cout << "name:" << monster->getName() << std::endl;
        std::cout << monster->getIntro() << std::endl;
        std::cout << "health:" << monster->getHealth() << std::endl;
        std::cout << "damage:" << monster->getDamage() << std::endl;
        std::cout << "roll :" << monster->getRollMod() << std::endl;

        monster->changeDamage(5);
        monster->changeRollMod(1);
        std::cout << "updated damage:" << monster->getDamage() << std::endl;
        std::cout << "updated roll :" << monster->getRollMod() << std::endl;

        delete monster;
        delete[] factory;
        i++;
*/




return 0;

}
