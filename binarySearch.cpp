#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns
// location of k in given Aay A[low..high] is present,
// otherwise -1
// low = 0, high = n-1
int binarySearch(int A[], int low, int high, int k)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (A[mid] == k)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subAay
        if (A[mid] > k)
            return binarySearch(A, low, mid - 1, k);

        // Else the element can only be present
        // in right subAay
        return binarySearch(A, mid + 1, high, k);
    }
  return -1;
}

// Algorithm binarySearch(A[0..n-1], low, high, k)
// //input: sorted array A[0..n-1], lowest index of A low, highest index of A high, search key k.
// //output: location of k in array A[0..n-1], or -1 if no element equal to k is found.
// if high >= low
//     mid <- low + (high - low) / 2
//     if A[mid] == k return mid
//     if A[mid] > k 
//         high = mid - 1
//         return binarySearch(A, low, high, k)
//     low = mid + 1
//     return binarySearch(A, low, high, k)
    
// return -1
// Driver code
int main()
{
    int A[] = { 2, 3, 4, 10, 40 };
    int query = 3;
    int n = sizeof(A) / sizeof(A[0]);
    int result = binarySearch(A, 0, n - 1, query);
    if (result == -1) cout << "Element is not present in Aay";
    else cout << "Element is present at indek " << result;
    return 0;
}
