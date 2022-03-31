#ifndef __TITLE_TEST_HPP__
#define __TITLE_TEST_HPP__

#include "gtest/gtest.h"
#include "title.hpp"


TEST(TitleTest, constructorInit)
{
    title* T1 = new title(1);
    EXPECT_EQ(T1->getTitle(),"Bard");
    delete T1;

    T1 = new title(2);
    EXPECT_EQ(T1->getTitle(),"Ranger");
    delete T1;
}


#endif