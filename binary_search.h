

// BinarySearch to find/return the first index whose value passes the test function.
// Which means:
//   BinarySearch(a, p1, p2, test) == Min(i) such that test(a[i]) == true && p1 <= i <= p2
// If there's no such i, the function returns -1.
//
// The assumption is that test(a[j]) == true if j >= i.
// The input array `a` and the test function `test` should satisfy the assumption.
int BinarySearch(int a[], int p1, int p2, bool (*test)(int), bool debug);
int BinarySearch(int a[], int p1, int p2, bool (*test)(int));
