#include <iostream>

using namespace std;

int K, L, M, N, D;

int main(void) {
    cin >> K >> L >> M >> N >> D;

    int ct = 0;

    for(int i = 1; i <= D; i++) {
        if(i % K == 0 || i % L == 0 || i % M == 0 || i % N == 0) ct++;
    }

    cout << ct << endl;

    return 0;
}
