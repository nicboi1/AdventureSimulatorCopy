#ifndef __RACE_TEST_HPP__
#define __RACE_TEST_HPP__

#include "gtest/gtest.h"
#include "race.hpp"

TEST(ElfTest, eName){
        Elf *test=new Elf();
        EXPECT_EQ(test->getName(),"Elf");
}
TEST(ElfTest, eID){
        Elf *test=new Elf();
        EXPECT_EQ(test->getID(),1);
}
TEST(DwarfTest, dName){
        Dwarf *test=new Dwarf();
        EXPECT_EQ(test->getName(),"Dwarf");
}
TEST(DwarfTest, dID){
        Dwarf *test=new Dwarf();
        EXPECT_EQ(test->getID(),2);
}
TEST(HumanTest, huName){
        Human *test=new Human();
        EXPECT_EQ(test->getName(),"Human");
}
TEST(HumanTest, huID){
        Human *test=new Human();
        EXPECT_EQ(test->getID(),3);
}
TEST(HalflingTest, haName){
        Halfling *test=new Halfling();
        EXPECT_EQ(test->getName(),"Halfling");
}
TEST(HalflingTest, haID){
        Halfling *test=new Halfling();
        EXPECT_EQ(test->getID(),4);
}


#endif
