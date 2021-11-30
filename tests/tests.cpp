#include "gtest/gtest.h"

#include "BookTests.hpp"
#include "SortTests.hpp"
#include "SearchTests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
