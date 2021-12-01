#include "gtest/gtest.h"

#include "BookTests.hpp"
#include "BundleTests.hpp"
#include "BookSystemTests.hpp"
#include "LibrarySystemTests.hpp"
#include "SortTests.hpp"
#include "SearchTests.hpp"
#include "PersonTests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}