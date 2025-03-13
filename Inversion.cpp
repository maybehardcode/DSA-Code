#include <iostream>
#include <vector>


void Merge(const std::vector<int>& B, const std::vector<int>& C, std::vector<int>& A) {
    int p = B.size();
    int q = C.size();


    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (B[i] <= C[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = C[j];
            j++;
        }
        k++;
    }

    while (i < p) {// IF J == q, C IS COOKED
        A[k++] = B[i++]; //copy rest of b
    }

    while (j < q) { //IF I == P, B IS DONZO
        A[k++] = C[j++]; //copy rest of c
    }
}
int inversion(const std::vector<int>& B, const std::vector<int>& C, std::vector<int>& A, int count) {
    int p = B.size();
    int q = C.size();


    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (B[i] <= C[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = C[j];
            j++;
        }
        k++;
    }

    while (i < p) {// IF J == q, C IS COOKED
        A[k++] = B[i++]; //copy rest of b
    }

    while (j < q) { //IF I == P, B IS DONZO
        A[k++] = C[j++]; //copy rest of c
    }
    return count;
}

void Mergesort(std::vector<int>& A) {
    int n = A.size();
    int count = 0;
    if (n > 1) {
        int mid = n / 2;

        std::vector<int> B(A.begin(), A.begin() + mid); //copy A[0..n/2 -1] to B
        std::vector<int> C(A.begin() + mid, A.end()); //copy A[n/2.. n-1] to C

        Mergesort(B);
        Mergesort(C);

        count += Merge(B, C, A, count);
    }
}

int main() {
    std::vector<int> A = {5, 3, 8, 4, 2, 7, 1, 6};
    Mergesort(A);

    std::cout << "Sorted array: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
