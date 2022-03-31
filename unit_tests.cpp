#include "gtest/gtest.h"
#include "attribute_test.hpp"
#include "race_test.hpp"
#include "att_list_test.hpp"
#include "monster_test.hpp"
#include "race_stats_test.hpp"
#include "title_test.hpp"
#include "character_test.hpp"



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

