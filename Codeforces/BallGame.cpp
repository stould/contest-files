#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, c = 0, act = 1;
vector<int> ans;

int main(void) {
    cin >> n;

    while(c != n) {
         c += 1;
         ans.push_back((act + c) % (n) == 0 ? n : (act + c) % (n));
         act += c;
    }
    for(int i = 0; i < n - 1; i++) {
        if(i == n - 2) {
            cout << ans[i] << endl;
        } else {
            cout << ans[i] << " ";
        }
    }

    return 0;
}
