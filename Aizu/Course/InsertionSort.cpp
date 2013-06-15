#include <iostream>
#include <stdio.h>

using namespace std;

int N, v[110];

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i];

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j == N - 1) {
                cout << v[j] << endl;
            } else {
                cout << v[j] << " ";
            }
        }
        int key = v[i];
        int id = i - 1;
        while(id >= 0 && v[id] > key) {
            v[id + 1] = v[id];
            id--;
        }
        v[id + 1] = key;
    }
    for(int j = 0; j < N; j++) {
        if(j == N - 1) {
            cout << v[j] << endl;
        } else {
            cout << v[j] << " ";
        }
    }
    return 0;
}
