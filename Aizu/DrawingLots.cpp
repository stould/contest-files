#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> v(N + 1);

    for(int i = 1; i < N + 1; i++) {
        v[i] = i;
    }
    int p, t;
    for(int i = 1; i < N + 1; i++) {
        cin >> p >> t;
        swap(v[p], v[t]);
    }
    for(int i = 1; i < N + 1; i++) {
        cout << v[i] << endl;
    }
    return 0;
}
