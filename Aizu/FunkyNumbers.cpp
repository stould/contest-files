#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, d = 0;
vector<ll> v;

int main(void) {
    cin >> n;
    for(int i = 1L; ((i * (i + 1L)) / 2L) <= 1000000000L; i += 1) {
        v.push_back((i * (i + 1L)) / 2L);
    }
    for(int i = 0; i < v.size(); i++) {
        int low = 0, high = v.size(), mid;
        bool found = false;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(v[mid] + v[i] == n) {
                found = true; break;
            } else if(v[mid] > n - v[i]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(found) {
            cout << "YES" << endl; return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
