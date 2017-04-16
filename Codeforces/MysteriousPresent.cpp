#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n, w, h;
vector<pair<int, int> > p;

int dp[5010];

int main(void) {
    cin >> n >> w >> h;
    for(int i = 0; i < n; i++) {
        int ta, tb;
        cin >> ta >> tb;
        p.push_back(make_pair(ta, tb));
    }
    p.resize((unique(p.begin(), p.end())) - p.begin());
    return 0;
}
