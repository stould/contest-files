#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    freopen("in.in", "r", stdin);
    freopen("cout.out", "w", stdout);
    int n;
    cin >> n;
    while(n != 0) {
        vector<long long> v;
        v.push_back(n);
        while(n != 1) {
            if(n % 2 == 0) {
                n *= 0.5;
            } else {
                n = n * 3 + 1;
            }
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        cout << v[v.size() - 1] << endl;
        v.clear();
        cin >> n;
    }
    return 0;
}
