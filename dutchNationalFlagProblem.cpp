#include <iostream>
#include <string>
using namespace std;

void rearrangeString(string &p) {
    int low = 0, mid = 0, high = p.size() - 1;

    while (mid <= high) {
        if (p[mid] == 'R') {
            swap(p[low], p[mid]);
            low++;
            mid++;
        } else if (p[mid] == 'G') {
            mid++;
        } else {  // p[mid] == 'B'
            swap(p[mid], p[high]);
            high--;
        }
    }
}

int main() {
    string p = "BBRRGGBRGGBR";
    rearrangeString(p);
    cout << "Rearranged string: " << p << endl;
    return 0;
}
