#ifndef __C_T_HPP__
#define __C_T_HPP__

#include "character.hpp"
#include "gtest/gtest.h"

/*
TEST(characterTest, elf_paladin){


	character* myChar = new character();



	int reroll = myChar -> getRerollCount();
	EXPECT_EQ(reroll, 1);

	int damage = myChar -> getDamageMod();
	EXPECT_EQ(damage, 3);

	int rollMod = myChar -> getRollMod(); 
	EXPECT_EQ(rollMod, -2);

	int hp = myChar -> getHP();
	EXPECT_EQ(hp, 48);

	
}
*/
TEST(characterTest, dwarf_bard){


        character* myChar = new character();



        int reroll = myChar -> getRerollCount();
        EXPECT_EQ(reroll, 1);

        int damage = myChar -> getDamageMod();
        EXPECT_EQ(damage, 1);

        int rollMod = myChar -> getRollMod();
        EXPECT_EQ(rollMod, 5);

        int hp = myChar -> getHP();
        EXPECT_EQ(hp, 25);


	myChar -> add_player_att(1);
	int rerollCount = myChar -> getRerollCount();
	int damMod = myChar -> getDamageMod();
	int rollmod = myChar -> getRollMod();


	EXPECT_EQ(rerollCount, 2);
	EXPECT_EQ(damMod, 4);
	EXPECT_EQ(rollmod, 5);
	
	

	myChar -> remove_att(2);

	int newDamage = myChar -> getDamageMod();
	EXPECT_EQ(newDamage, 3);

	int newRR = myChar -> getRerollCount();
	EXPECT_EQ(newRR, 1);

	int newRollMod = myChar -> getRollMod();
	EXPECT_EQ(newRollMod, 5);		




	myChar -> remove_att(1);

	int newerDamage = myChar -> getDamageMod();
	EXPECT_EQ(newerDamage, 0);
	
	int newerRR = myChar -> getRerollCount();
	EXPECT_EQ(newerRR, 0);

	int newerRollMod = myChar -> getRollMod();
	EXPECT_EQ(newerRollMod, 5);


	myChar -> remove_att(1);

        newerDamage = myChar -> getDamageMod();
        EXPECT_EQ(newerDamage, 0);

        newerRR = myChar -> getRerollCount();
        EXPECT_EQ(newerRR, 0);

        newerRollMod = myChar -> getRollMod();
        EXPECT_EQ(newerRollMod, 5);



}

























#endif
