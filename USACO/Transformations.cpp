/*
ID: jeferso1
LANG: C++
TASK: transform
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int i, j;

vector<string> rotate90(vector<string>& v) {
    vector<string> ans(v.size());
    int o = 0;

    for(j = 0; j < v.size(); j++) {
        for(i = v.size() - 1; i >= 0; i--) {
            ans[o] += v[i][j];
        }
        o++;
    }
    return ans;
}

vector<string> rotate180(vector<string>& v) {
    vector<string> ans(v.size());

    for(int i = v.size() - 1, x = 0; i >= 0 && x < v.size(); i--, x++) {
        string tmp;
        for(int j = v.size() - 1, y = 0; j >= 0 && y < v.size(); j--, y++) {
            tmp += v[i][j];
        }
        ans[x] = tmp;
    }
    return ans;
}

vector<string> rotate270(vector<string>& v) {
    vector<string> ans(v.size(), (v.size(), ""));

    for(int i = v.size() - 1, x = 0; i >= 0 && x < v.size(); i--, x++) {
        for(int j = 0, y = 0; j < v.size() && y < v.size(); j++, y++) {
            ans[x][y] = v[j][i];
        }
    }
    return ans;
}

vector<string> rotate_reflection(vector<string>& v) {
    vector<string> ans = v;
    reverse(ans[0].begin(), ans[0].end());
    reverse(ans[1].begin(), ans[1].end());
    reverse(ans[2].begin(), ans[2].end());
    return ans;
}

vector<string> cmb1(vector<string>& v) {
    vector<string> ans = rotate_reflection(v);
    vector<string> an = rotate90(ans);
    return an;
}


vector<string> cmb2(vector<string>& v) {
    vector<string> ans = rotate_reflection(v);
    vector<string> an = rotate180(ans);
    return an;
}

vector<string> cmb3(vector<string>& v) {
    vector<string> ans = rotate_reflection(v);
    vector<string> an = rotate90(ans);
    return an;
}

int getAns(vector<string>& q, vector<string>& a, vector<string>& tmp) {
    tmp = rotate90(q);
    if(tmp == a) return 1;
    tmp = rotate180(q);
    if(tmp == a) return 2;
    tmp = rotate270(q);
    if(tmp == a) return 3;
    tmp = rotate_reflection(q);
    if(tmp == a) return 4;
    tmp = cmb1(q);
    if(tmp == a) return 5;
    tmp = cmb2(q);
    if(tmp == a) return 5;
    tmp = cmb3(q);
    if(tmp == a) return 5;
    if(q == a) return 6;
    return 7;
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int N;

    cin >> N;
    vector<string> q(N);
    vector<string> a(N);

    getline(cin, q[0]);
    for(i = 0; i < N; i++) {
        getline(cin, q[i]);
    }

    for(i = 0; i < N; i++) {
        getline(cin, a[i]);
    }

    vector<string> tmp;

    cout << getAns(q, a, tmp) << endl;
    return 0;
}
