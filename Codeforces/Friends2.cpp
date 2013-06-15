#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <stdio.h>

using namespace std;

int n, d;

struct Friend {
    string a, b;
    int c;

    Friend() {}
    Friend(string _a, string _b, int _c) {
         a = _a;
         b = _b;
         c = _c;
    }
};

vector<Friend> memo;

int main(void) {
    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        string a, b; int c;
        cin >> a >> b >> c;
        memo.push_back(Friend(a, b, c));
    }
    vector<bool> used(n+2, false);
    vector<string> ans;

    int i, j;

    for(i = 0; i < (int) memo.size(); i++) {
        for(j = 0; j < (int) memo.size(); j++) {
            if(i != j && !used[i] && !used[j] && memo[i].a == memo[j].b && memo[i].b == memo[j].a) {
                int ta = memo[i].c - memo[j].c;
                int tb = memo[j].c - memo[i].c;

                if((ta > 0 && ta <= d) || (tb > 0 && tb <= d)) {
                    ans.push_back(memo[i].a + " " + memo[j].a);
                    used[i] = used[j] = true;
                    break;
                }
            }
        }
    }
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    for(i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
