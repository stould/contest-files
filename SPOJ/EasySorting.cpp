#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick(vector<string>& v, int low, int high) {
    int i = low, j = high;

    string mid = v[(low + high) / 2];

    do {
        while(v[i] < mid) i++;
        while(v[j] > mid) j--;

        if(i <= j) {
            swap(v[i], v[j]);
            i++; j--;
        }
    } while(i <= j);
    if(i < high) quick(v, i, high);
    if(j > low) quick(v, low, j);
}

int main(void) {
    int n, c;
    cin >> n;
    while(n--) {
        cin >> c;
        vector<string> v(c);
        for(int i = 0; i < c; i++) {
            cin >> v[i];
        }

        quick(v, 0, v.size()-1);

        for(int i = 0; i < c; i++) {
            cout << v[i] << endl;
        }
    }
}
