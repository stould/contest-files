#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int i, j, n, hg, ag;

struct team {
    string name;
    int points, gm, gs;

    bool operator<(const team& t) const {
        if(points != t.points) {
            return points > t.points;
        } else if(gm - gs != t.gm - t.gs) {
            return (gm - gs) > (t.gm - t.gs);
        } else {
            return (gm > t.gm);
        }
    }
};

int strtoint(string s) {
    int ans = 0, base = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        ans += (s[i] - '0') * pow(10, base); base += 1;
    }
    return ans;
}

int main(void) {
    scanf("%d", &n);
    vector<team> tm(n);
    for(i = 0; i < n; i++) {
        cin >> tm[i].name;
        tm[i].points = tm[i].gm = tm[i].gs = 0;
    }
    for(i = 0; i < (int) (n * (n - 1)) / 2; i++) {
        string a, h, ta, tb;
        cin >> h >> a;
        for(j = 0; j < (int) h.size(); j++) {
            if(h[j] == '-') break;
        }
        ta = h.substr(0, j);
        tb = h.substr(j+1, h.size()-j - 1);
        for(j = 0; j < (int) a.size(); j++) if(a[j] == ':') break;
        hg = strtoint(a.substr(0, j));
        ag = strtoint(a.substr(j+1, a.size()-j - 1));
        for(j = 0; j < n; j++) {
            if(tm[j].name == ta) {
                tm[j].gm += hg;
                tm[j].gs += ag;
                int outcome = 0;
                if(hg > ag) {
                    outcome = 3;
                } else if(hg == ag) {
                    outcome = 1;
                }
                tm[j].points += outcome;
            } else if(tm[j].name == tb) {
                tm[j].gm += ag;
                tm[j].gs += hg;
                int outcome = 0;
                if(hg < ag) {
                    outcome = 3;
                } else if(hg == ag) {
                    outcome = 1;
                }
                tm[j].points += outcome;
            }
        }
    }
    sort(tm.begin(), tm.end());
    vector<string> ans;
    for(i = 0; i < (int) n / 2; i++) {
        ans.push_back(tm[i].name);
    }
    sort(ans.begin(), ans.end());
    for(i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
