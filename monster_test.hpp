#ifndef __MONSTER_TEST_HPP__
#define __MONSTER_TEST_HPP__

#include "gtest/gtest.h"
#include "monster_factory.hpp"
#include "monster.hpp"


TEST(BaseMonsterTest, constructorInit)
{
    MonsterFactory factory;
    Monster* base = factory.makeMonster();

    int health = base->getHealth();
    int damage = base->getDamage();
    int roll_ = base->getRollMod();
    
    EXPECT_EQ(health,10);
    EXPECT_EQ(damage,4);
    EXPECT_EQ(roll_,0);
}

TEST(BaseMonsterTest, baseStateMod)
{
    MonsterFactory factory;
    Monster* base = factory.makeMonster();

    base->changeDamage(-1);
    base->changeRollMod(1);

    int health = base->getHealth()-2;
    base->damageHealth(2);
    
    EXPECT_EQ(base->getHealth(),health);
    EXPECT_EQ(base->getDamage(),3);
    EXPECT_EQ(base->getRollMod(),1);
}

TEST(BossMonsterTest, bossStateMod)
{
    BossMonsterFactory factory;
    Monster* boss = factory.makeMonster();

    boss->changeDamage(-100);
    boss->changeRollMod(-1);

    int health = boss->getHealth()-4;
    boss->damageHealth(4);
    
    EXPECT_EQ(boss->getHealth(), health);
    EXPECT_EQ(boss->getDamage(),1); // test min boundary 
    EXPECT_EQ(boss->getRollMod(),0); // test min boundary 
}


TEST(BossMonsterTest, constructorInit)
{
    BossMonsterFactory factory;
    Monster* boss = factory.makeMonster();

    int health = boss->getHealth();
    int damage = boss->getDamage();
    int roll_ = boss->getRollMod();
    
    EXPECT_EQ(health,20);
    EXPECT_EQ(damage,8);
    EXPECT_EQ(roll_,0);
}


TEST(BattleTest, battleSim)
{
    MonsterFactory factory;
    Monster* base = factory.makeMonster();
    
    BossMonsterFactory factory1;
    Monster* boss = factory1.makeMonster();

    // BASE: health{10} damage{4} | BOSS: health{20} damage{8}
    base->attack(boss); //-4
    base->attack(boss); //-4
    boss->attack(base); // -8

    EXPECT_EQ(base->getHealth(),2);
    EXPECT_EQ(boss->getHealth(),12);

    base->changeDamage(10);
    base->attack(boss);
    EXPECT_EQ(boss->isAlive(),false);
 
}
    

#endif 
