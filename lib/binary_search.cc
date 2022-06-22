#include <iostream>

int BinarySearch(int a[], int p1, int p2, bool (*test)(int)) {
  if (p1 > p2) {
    return -1;
  }
  if (!test(a[p2])) {
    return -1;
  }
  if (test(a[p1])) {
    return p1;
  }

  p2 -= 1;
  p1 += 1;
  // invariant condition for the while loop below:
  //  !test(a[p1-1]) && test(a[p2+1]) && p1-1 and p2+1 indices are valid
  while (p1 < p2) {
    int mid = (p1 + p2) / 2;
    if (test(a[mid])) {
      p2 = mid - 1;
    } else {
      p1 = mid + 1;
    }
  }

  if (test(a[p2])) {
    return p2;
  } else {
    return p2+1;
  }
}
