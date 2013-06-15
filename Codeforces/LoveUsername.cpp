#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

int n, c = 0;

int main(void) {
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++) {
        int ca = 0, cb = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(v[j] > v[i]) ca += 1;
            if(v[j] < v[i]) cb += 1;
        }
        if(ca == i || cb == i) c++;
    }
    cout << c << endl;
    return 0;
}


