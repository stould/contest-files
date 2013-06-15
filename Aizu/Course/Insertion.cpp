#include <iostream>
#include <stdio.h>

using namespace std;

int n, v[110];

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 1; i < n; i++) {
        for(int k = 0; k < n; k++) {
            if(k != n - 1) {
                cout << v[k] << " ";
            } else {
                cout << v[k] << endl;
            }
        }
        int key = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j -= 1;
        }
        v[j + 1] = key;
    }
    for(int k = 0; k < n; k++) {
        cout << v[k] << " ";
    }
    return 0;
}
