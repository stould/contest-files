#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> d;

int main(void) {
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp; d.push_back(tmp);
    }
    ans = min(d[0], d[d.size()-1]);
    for(int i = 1; i < n; i++) {
        ans = min(ans, max(d[i], d[i - 1]));
    }
    cout << ans << endl;
    return 0;
}
