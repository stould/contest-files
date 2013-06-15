#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k;

int main(void) {
    cin >> n >> k;
    vector<ll> v(n); vector<ll> cp = v;

    v.resize(unique(b.begin(), v.end()) - v.begin());

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int stop = -1, base = 0;

    for(int start = 0; start <= n; start++) {
        if(k >= start && k <= start*n) { stop = start - 1; base = (start - 1) * n; break;}
    }

    int index = (base + k - 1) % n;

    cout << v[stop]  << " " << v[index] << endl;
    return 0;
}
