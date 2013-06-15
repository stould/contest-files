#include <iostream>
#include <algorith>
#include <vector>
#include <cmath>

using namespace std;

int s[10] = {10, 6, 1, 3, 7, 9, 8, 2, 4, 5};

void mergesort(vector<int> &v, int low, int high) {
    if(low < high) {
        int mid = (int) floor(low + high) / 2;
        mergesort(v, low, mid);
        mergesort(v, mid+1, high);
        merge(v, low, mid, high);
    }
}

void merge(vector<int> &v, int low, int mid, int high) {
    vector<int> left(mid-low+1), right(high-mid);
}

int main(void) {
    vector<int> v(s, s + 10);
    for(int i = 0; i < 10; i++) {
        cout << v[i] << " ";
    }
    return 0;
}
