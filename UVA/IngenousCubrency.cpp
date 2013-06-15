#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

const int MAX = 10000;

ll cubes[21];
ll ways[10001];

ll n;

int main(void) {
    for(int i = 0; i < 21; i++) {
        cubes[i] = (i + 1) * (i + 1) * (i + 1);
    }
    ways[0] = 1;
    for(int i = 0; i < 21; i++) {
        ll c = cubes[i];
        for(int j = c; j <= MAX; j++) {
            ways[j] += ways[j - c];
        }
    }
    while(cin >> n) {
        cout << ways[n] << endl;
    }
    return 0;
}
