#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define REP(i, n) for(i = 0; i < n; i++)

int main(void) {
    freopen("9.in", "r", stdin);
    int i, j, N, K, F, T;

    cin >> N >> K;

    vector<int> v(N + 1, 0);

    REP(i, K) {
        cin >> F >> T;
        v[F] += 1;
        v[T + 1] -= 1;
    }
    vector<int> values(N);
    int s = 0;
    REP(i, N) {
        s += v[i];
        values[i] = s;
    }
    sort(values.begin(), values.end());
    cout << (values[N / 2]) << endl;
    return 0;
}
