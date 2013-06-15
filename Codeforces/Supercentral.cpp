#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <utility>

using namespace std;

pair<int, int> p[210];
int n, ans = 0;

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for(int i = 0; i < n; i++) {
        bool up, down, left, right;
        up = down = left = right = false;
        for(int j = 0; j < n; j++) {
            if(p[i].first > p[j].first && p[i].second == p[j].second) right = true;
            if(p[i].first < p[j].first && p[i].second == p[j].second) left = true;
            if(p[i].first == p[j].first && p[i].second < p[j].second) down = true;
            if(p[i].first == p[j].first && p[i].second > p[j].second) up = true;
        }
        if(down && up && right && left) ans++;
    }
    cout << ans << endl;
    return 0;
}
