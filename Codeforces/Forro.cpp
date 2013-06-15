#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)

using namespace std;

int i, j, n, m, index, c;
vector<pair<int, int> > graph[520];
string f, t;

int main(void) {
    while(cin >> n && n != 0) {
        REP(i, 520) graph[i].clear();
        map<string, int> mp;
        map<int, string> mx;

        index = 1;

        REP(i, n) {
            cin >> f >> t >> c;
            if(mp[f] == 0) {
                mp[f] = index;
                mp[index] = f;
                index++;
            }
            if(mp[t] == 0) {
                mp[t] = index;
                mp[index] = t;
                index++;
            }
            graph[mp[f]].push_back()
        }
    }
    return 0;
}
