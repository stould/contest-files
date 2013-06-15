#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int i, n, x;
vector<int> v(n);

int median() {
    return v[(int)floor((v.size() + 1) / 2) - 1];
}

int main(void) {
    cin >> n >> x;
    v.resize(n);
    for(i = 0; i < n; i++) {
        cin >> v[i];
    }

    int added = 0, a = 0, b = 100000;

    if(count(v.begin(), v.end(), x) == 0) {
        v.push_back(x); added++;
    }

    sort(v.begin(), v.end());
    while(median() != x) {
        int tmp = median();
        if(tmp > x) {
            v.push_back(v[0] - 1);
        } else {
            v.push_back(v[v.size()-1] + 1);
        }
        added++;
        sort(v.begin(), v.end());
    }
    cout << added << endl;
    return 0;
}
