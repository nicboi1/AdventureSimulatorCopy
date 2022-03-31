#ifndef __RST_HPP__
#define __RST_HPP__

#include <iostream>
#include "gtest/gtest.h"
#include "race_stats.hpp"


TEST(race_stats, basic_add){

	race_stats myStats(1);
	int toCheck = myStats.get_dam_mod();
	int rollMD = myStats.get_roll_mod();
	int reroll = myStats.get_total_reroll();


	EXPECT_EQ(toCheck, 3);
	EXPECT_EQ(rollMD, 0);
	EXPECT_EQ(reroll, 1);



}

TEST(race_stats, unknownNum){


	testing::internal::CaptureStdout();
	
        race_stats myStats(7);
	
	string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "DEV NOTE, UNEXPECTED NUM\n");

}


TEST(race_stats, compelex_out){

	race_stats myStats(1);
	myStats.addtoList(2);
	myStats.addtoList(3);
	myStats.addtoList(4);

	myStats.removeAtt(2);


        int toCheck = myStats.get_dam_mod();
        int rollMD = myStats.get_roll_mod();
        int reroll = myStats.get_total_reroll();

	EXPECT_EQ(toCheck, 3);
	EXPECT_EQ(rollMD, 3);
	EXPECT_EQ(reroll, 3);


}













#endif
