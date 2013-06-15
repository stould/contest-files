#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int N, P, tmp, ans, maze[1010][1010], vis[1010];
string line;
vector<int> v;

void split(vector<int>& v, const string& s) {
    istringstream ss(s, istringstream::in);
    v.clear(); int t;
    while(ss >> t) {
        v.push_back(t);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int x = 0; x < N; x++) {
        memset(maze, 0, sizeof(maze));
        cin >> P;
        cin.ignore();
        int ans = 100000000;
        for(int i = 1; i <= P; i++) {
            getline(cin, line);
            split(v, line); int t = 0;
            for(int j = 0; j < (int) v.size(); j++) {
                maze[i][v[j]] = 2; t += 1;
            }
            if(t < ans) {
                ans = t;
            }
        }
        vector<int> a;
        for(int i = 1; i <= P; i++) {
            int tmp = 0;
            for(int j = 1; j <= P; j++) if(maze[i][j] == 2) tmp += 1;
            if(tmp == ans) {
                a.push_back(i);
            }
        }
        for(int i = 0; i < a.size(); i++) {
            if(i == a.size() - 1) {
                cout << a[i] << endl;
            } else {
                cout << a[i] << " ";
            }
        }
    }
    return 0;
}
