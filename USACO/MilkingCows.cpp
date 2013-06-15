/*
ID: jeferso1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

struct sort_pred {
    bool operator()(const pair<int,int> &left, const pair<int,int> &right) {
        return left.second - right.first;
    }
};
int main() {
	//freopen("milk2.in", "r", stdin);
	//freopen("milk2.out", "w", stdout);

	int i, a, b, n;

	scanf("%d", &n);
	vector<pair<int, int> > v;

	for(i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
	}
    sort(v.begin(), v.end(), sort_pred());

    int low = v[i].first, high = v[i].second;
    int run  = high - low;
    int stop = 0;
    for(i = 1; i < v.size(); i++) {
        if(v[i].first <= high) {
            high = max(high, v[i].second);
        } else {
            run = max(run, high - low);
            stop = max(stop, v[i].first - high);
            low = v[i].first;
            high = v[i].second;
        }
    }

	printf("%d %d\n", run, stop);

	return 0;
}

