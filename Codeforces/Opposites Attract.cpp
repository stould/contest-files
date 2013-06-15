#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

ll n, ways = 0;

int abs(int a) {
    return a < 0 ? -a : a;
}

ll mais[20], menos[20];

int main() {
    cin >> n;
    for(int i = 0; i < 20; i++) { mais[i] = 0L; menos[i] = 0L; }

    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(tmp < 0) {
            tmp = abs(tmp);
            menos[tmp]++;
        } else {
            mais[tmp]++;
        }
    }
    for(int i = 1; i < 11; i++) {
        ways += mais[i] * menos[i];
    }
    ways += (mais[0] * (mais[0] - 1)) / 2;
    cout << ways << endl;
    return 0;
}
