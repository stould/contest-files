#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, count = 0, v[100010], ret = 0, last = 100000000000;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] != last) {
            last = v[i];
            count = 1;
        } else {
            count += 1L;
        }
        ret += (ll) count;
    }

    cout << ret << endl;
    return 0;
}
