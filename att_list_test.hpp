#ifndef __ATT_LIST_TEST__
#define __ATT_LIST_TEST__


#include "gtest/gtest.h"
#include "att_list.hpp"



TEST(att_list, basic_construction){

	att_list myAttList;
	EXPECT_EQ(myAttList.getSize(),0);	

}


TEST(att_list, canAdd){

	att_list myAttList;
	myAttList.addAtt(1);
	myAttList.addAtt(2);
	myAttList.addAtt(3);
	myAttList.addAtt(4);
	
	EXPECT_EQ(myAttList.getSize(),4);

}


TEST(att_list, canRemove){

	att_list myAttList;
        myAttList.addAtt(1);
        myAttList.addAtt(2);
        myAttList.addAtt(3);
        myAttList.addAtt(4);

	myAttList.removeAtt(1);

	EXPECT_EQ(myAttList.getSize(), 3);

}


TEST(att_list, calcReroll){

        att_list myAttList;
        myAttList.addAtt(1);
        myAttList.addAtt(2);
        myAttList.addAtt(3);
        myAttList.addAtt(4);

     	int totalReroll = myAttList.getTotalReroll();

        EXPECT_EQ(totalReroll, 4);

}


TEST(att_list, calcRollMod){

        att_list myAttList;
        myAttList.addAtt(1);
        myAttList.addAtt(2);
        myAttList.addAtt(3);
        myAttList.addAtt(4);

        int totalRollMod = myAttList.getTotalRollMod();

        EXPECT_EQ(totalRollMod, 3);

}


TEST(att_list, calcTotalDamMod){

        att_list myAttList;
        myAttList.addAtt(1);
        myAttList.addAtt(2);
        myAttList.addAtt(3);
        myAttList.addAtt(4);

        int totalDamMod = myAttList.getTotalDamMod();

        EXPECT_EQ(totalDamMod, 4);

}




#endif
