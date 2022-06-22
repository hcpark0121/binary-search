#include "gtest/gtest.h"

#include "lib/binary_search.h"

namespace {

bool GreaterThanZero(int value) {
  return value > 0;
}

TEST(BinarySearch, InvalidInputs) {
  int a[] = {0, 0, 1, 1};
  EXPECT_EQ(-1, BinarySearch(a, 2, 1, &GreaterThanZero));;;;
}

TEST(BinarySearch, NoValidElement) {
  int a[] = {0, 0, 1, 1};
  EXPECT_EQ(-1, BinarySearch(a, 1, 1, &GreaterThanZero));;;;
}

TEST(BinarySearch, IndexFound) {
  int a[] = {0, 0, 1, 1};
  EXPECT_EQ(2, BinarySearch(a, 2, 2, &GreaterThanZero));;;;
  EXPECT_EQ(2, BinarySearch(a, 1, 2, &GreaterThanZero));;;;
  EXPECT_EQ(2, BinarySearch(a, 0, 2, &GreaterThanZero));;;;

  EXPECT_EQ(2, BinarySearch(a, 2, 3, &GreaterThanZero));;;;
  EXPECT_EQ(2, BinarySearch(a, 1, 3, &GreaterThanZero));;;;
  EXPECT_EQ(2, BinarySearch(a, 0, 3, &GreaterThanZero));;;;
}

TEST(BinarySearch, IndexFoundFromLargeArrays) {
  int a[100000];
  for (int i = 0; i<50000; i++) {
    a[i] = 0;
  }
  for (int i = 50000; i<100000; i++) {
    a[i] = 1;
  }

  EXPECT_EQ(50000, BinarySearch(a, 0, 99999, &GreaterThanZero));;;;
  EXPECT_EQ(50000, BinarySearch(a, 1, 99999, &GreaterThanZero));;;;
  EXPECT_EQ(50000, BinarySearch(a, 0, 99998, &GreaterThanZero));;;;
}
}
