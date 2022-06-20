#include "binary_search.h"

#include <iostream>

bool GreaterThanZero(int value) {
  return value > 0;
}

void RunTestsForSmallArrays() {
  int a[] = {0, 0, 1, 1};

  // Index not found.
  std::cout << "BinarySearch(a, 2, 1) = " << BinarySearch(a, 2, 1, &GreaterThanZero)
            << " should be -1.\n";
  std::cout << "BinarySearch(a, 1, 1) = " << BinarySearch(a, 1, 1, &GreaterThanZero)
            << " should be -1.\n";

  // Index 2 is returned.
  std::cout << "BinarySearch(a, 1, 2) = " << BinarySearch(a, 1, 2, &GreaterThanZero)
            << " should be 2.\n";
  std::cout << "BinarySearch(a, 0, 2) = " << BinarySearch(a, 0, 2, &GreaterThanZero)
            << " should be 2.\n";
  std::cout << "BinarySearch(a, 0, 3) = " << BinarySearch(a, 0, 3, &GreaterThanZero)
            << " should be 2.\n";
  std::cout << "BinarySearch(a, 2, 3) = " << BinarySearch(a, 2, 3, &GreaterThanZero)
            << " should be 2.\n";
  std::cout << "BinarySearch(a, 3, 3) = " << BinarySearch(a, 3, 3, &GreaterThanZero)
            << " should be 3.\n";
}

void RunTestsForLargerArrays() {
  int a[100000];
  for (int i = 0; i<50000; i++) {
    a[i] = 0;
  }
  for (int i = 50000; i<100000; i++) {
    a[i] = 1;
  }
  std::cout << "BinarySearch(a, 0, 99999) = " << BinarySearch(a, 0, 99999, &GreaterThanZero)
            << " should be 50000.\n";
  std::cout << "BinarySearch(a, 1, 99999) = " << BinarySearch(a, 1, 99999, &GreaterThanZero)
            << " should be 50000.\n";
  std::cout << "BinarySearch(a, 0, 99998) = " << BinarySearch(a, 0, 99998, &GreaterThanZero)
            << " should be 50000.\n";

  BinarySearch(a, 0, 99999, &GreaterThanZero, /*debug=*/true);
  BinarySearch(a, 1, 99999, &GreaterThanZero, /*debug=*/true);
  BinarySearch(a, 0, 99998, &GreaterThanZero, /*debug=*/true);
}

void RunTests() {
  RunTestsForSmallArrays();
  RunTestsForLargerArrays();
}

int main() {
  RunTests();
  return 0;
}
