#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, pass = 0;

int main(void) {
    cin >> n >> k; k--;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++) {
        if(v[i] >= v[k] && v[i] > 0) pass++;
    }
    cout << pass << endl;
    return 0;
}
