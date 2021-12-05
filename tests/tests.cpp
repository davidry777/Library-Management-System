#include "gtest/gtest.h"


#include "BookTests.hpp"
#include "BundleTests.hpp"
#include "BookSystemTests.hpp"
#include "SortTests.hpp"
#include "SearchTests.hpp"
#include "PersonTests.hpp"
#include "UserSystemTests.hpp"
#include "LoginSystemTests.hpp"
#include "LibrarySystemTests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}