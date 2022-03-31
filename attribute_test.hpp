#ifndef __ATT_TEST_HPP__
#define __ATT_TEST_HPP__

#include "gtest/gtest.h"
#include "attribute.hpp"



TEST(ElfTest, allaspects){

	att_elf* myElf = new att_elf();
	EXPECT_EQ(myElf->getID(),1);
	EXPECT_EQ(myElf->getRollMod(),0);
	EXPECT_EQ(myElf->getReroll(), true);
	EXPECT_EQ(myElf->getDamMod(), 3);

}


TEST(DwarfTest, allaspects){

	att_dwarf* myDwarf = new att_dwarf();
	EXPECT_EQ(myDwarf->getID(),2);
	EXPECT_EQ(myDwarf->getRollMod(),0);
	EXPECT_EQ(myDwarf->getReroll(), true);
	EXPECT_EQ(myDwarf->getDamMod(), 1);

}


TEST(HumanTest, allaspects){

        att_human* myhuman = new att_human();
        EXPECT_EQ(myhuman->getID(),3);
	EXPECT_EQ(myhuman->getRollMod(), 1);
        EXPECT_EQ(myhuman->getReroll(), true);
        EXPECT_EQ(myhuman->getDamMod(), 1);
	
}


TEST(HalflingTest, allaspects){

        att_halfling* myhalf = new att_halfling();
        EXPECT_EQ(myhalf->getID(),4);
        EXPECT_EQ(myhalf->getRollMod(), 2);
        EXPECT_EQ(myhalf->getReroll(), true);
        EXPECT_EQ(myhalf->getDamMod(),-1);


}



#endif
