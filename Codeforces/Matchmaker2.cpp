#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, m, a, b;

vector<pair<int, int> > ma;
vector<pair<int, int> > chance;

int main(void) {
    cin >> n >> m;
    int mat = 0, perf = 0;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        ma.push_back(make_pair(a, b));
    }
    sort(ma.begin(), ma.end());
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        vector<pair<int, int> >::iterator it = find(ma.begin(), ma.end(), p);
        if(it == ma.end() && (*ma.end()) != p) {
            chance.push_back(p);
        } else {
            mat++; perf++;
            ma.erase(it);
        }
    }
    for(int i = 0; i < (int) chance.size(); i++) {
        for(int j = 0; j < (int) ma.size(); j++) {
            if(chance[i].second == ma[j].second) {
                mat++;
                ma.erase(ma.begin() + j);
                break;
            }
        }
    }
    cout << mat << " " << perf << endl;
    return 0;
}
