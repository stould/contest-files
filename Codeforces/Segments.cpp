#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

int a, b, n, last;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(void) {
    cin >> n;
    vector<pair<int, int> > vp;
    for(int i = 0; i < n; i++) {
        cin >> a >> b; vp.push_back(make_pair(min(a, b), max(a, b)));
    }
    vector<int> ans;
    sort(vp.begin(), vp.end(), cmp);
    last = vp[0].second;
    ans.push_back(last);

    for(int i = 1; i < n; i++) {
        if(vp[i].first > last) {
            ans.push_back(vp[i].second);
            last = vp[i].second;
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] <<  " ";
    }
    return 0;
}
