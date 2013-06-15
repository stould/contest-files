#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

int vis[3], graph[4][4], cycle = 0;
vector<int> order;

void dfs(int x) {
    vis[x] = 1;
    for(int u = 0; u <= 2; u++) {
        if(graph[x][u] == 1 && vis[u] == 1) cycle = true;
        if(graph[x][u] == 1 && vis[u] == 0) dfs(u);
    }
    vis[x] = 2;
    order.push_back(x);
}

string s;

int main(void) {
    map<char, int> mp;
    map<int, char> ma;
    mp['A'] = 0; ma[0] = 'A';
    mp['B'] = 1; ma[1] = 'B';
    mp['C'] = 2; ma[2] = 'C';

    for(int i = 0; i < 3; i++) {
        vis[i] = 0;
        for(int j = 0; j < 3; j++) {
            graph[i][j] = 0;
        }
    }
    for(int i = 0; i < 3; i++) {
        cin >> s;
        if(s[1] == '<') {
            graph[mp[s[2]]][mp[s[0]]] = 1;
        } else {
            graph[mp[s[0]]][mp[s[2]]] = 1;
        }
    }
    for(int i = 2; i >= 0; i--) if(!vis[i]) dfs(i);
    if(cycle) {
        cout << "Impossible\n";
    } else {
        for(int i = 0; i < 3; i++) cout << ma[order[i]];
    }
    cout << "\n";
    return 0;
}

