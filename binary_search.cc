#include <iostream>
#include <math.h>


int BinarySearch(int a[], int p1, int p2, bool (*test)(int), bool debug) {
  int test_counts = 0;
  int n = p2 - p1 + 1;
  if (p1 > p2) {
    return -1;
  }
  if (!test(a[p2])) {
    return -1;
  }
  if (test(a[p1])) {
    return p1;
  }
  test_counts +=2;

  p2 -= 1;
  p1 += 1;
  // invariant condition for the while loop below:
  //   !test(a[p1-1]) && test(a[p2+1]) && p1-1 and p2+1 indices are valid
  while (p1 < p2) {
    // test invariant for debugging.
    if (debug && test(a[p1-1])) {
      std::cout << "test(a[p1-1]) returned true while it should be false. p1, p2: "
                << p1 << " " << p2 << '\n';
    }
    if (debug && !test(a[p2+1])) {
      std::cout << "!test(a[p2+1]) returned false while it should be true. p1, p2: "
                << p1 << " " << p2 << '\n';
    }

    int mid = (p1 + p2) / 2;
    test_counts += 1;
    if (test(a[mid])) {
      p2 = mid - 1;
    } else {
      p1 = mid + 1;
    }
  }

  test_counts += 1;
  if (debug) {
    std::cout << "The test function was called " << test_counts << " times.\n";
    std::cout << "log2(n) is " << log2(n) << "\n";
  }
  if (test(a[p2])) {
    return p2;
  } else {
    return p2+1;
  }
}

int BinarySearch(int a[], int p1, int p2, bool (*test)(int)) {
  return BinarySearch(a, p1, p2, test, false);
}
