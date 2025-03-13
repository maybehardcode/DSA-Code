#include <iostream>
//SelectionSort(A[0..n − 1])
//Sorts a given array by selection sort
//Input: An array A[0..n − 1] of orderable elements
//Output: Array A[0..n − 1] sorted in nondecreasing order
void selectionSort(int a[], int n) {
    int min = 0, temp = 0;
    for (int k = 0; k < n; k++) { //visual output
        std::cout << a[k] << " ";
    }
    std::cout << '\n';
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        for (int k = 0; k < n; k++) { //this is just visual output
            std::cout << a[k] << " ";
        }
        std::cout << '\n';
    }
}


//BubbleSort(A[0..n − 1])
//Sorts a given array by bubble sort
//Input: An array A[0..n − 1] of orderable elements
void bubbleSort(int a[], int n) {
    int temp = 0;
    for (int k = 0; k < n; k++) { //visual output
        std::cout << a[k] << " ";
    }
    std::cout << '\n';

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j+1] < a[j]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                for (int k = 0; k < n; k++) { //this is just visual output
                     std::cout << a[k] << " ";
                }
                std::cout << '\n';
            }
        }
    }
}
int main() {
    int a[7] = {89, 45, 68, 90, 29, 34, 17};
    int b[5] = {5, 4, 3, 2, 1};
    // selectionSort(a, 7);
    bubbleSort(a, 7);

    std::cout << '\n';
    return 0;
};