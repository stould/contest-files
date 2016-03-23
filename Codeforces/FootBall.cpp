#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int i, j;

struct team {
    string nome;
    int goal;
    int missed;
    int points;
    int games;

    team(string _nome, int _goal, int _missed) {
        nome = _nome;
        goal = _goal;
        missed = _missed;
        points = 0;
        games = 0;
    }

    bool operator<(const team& t) const {
        if(points != t.points) {
            return points > t.points;
        } else {
            int d = goal - missed;
            int e = t.goal - t.missed;

            if(d != e) {
                return d > e;
            } else {
                if(goal != t.goal) {
                    return goal > t.goal;
                } else {
                    return nome < t.nome;
                }
            }
        }
    }
};

int main(void) {
    vector<team> v;
    for(i = 0; i < 5; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        int oa = c[0] - '0';
        int ob = c[2] - '0';
        bool founda = false;
        bool foundb = false;
        for(j = 0; j < v.size(); j++) {
            if(v[j].nome == a && !founda) {
                founda = true;
                v[j].goal += oa;
                v[j].missed += ob;
                v[j].games += 1;
                if(oa > ob) {
                    v[j].points += 3;
                } else if(oa == ob) {
                    v[j].points += 1;
                }
            }
            if(v[j].nome == b && !foundb) {
                foundb = true;
                v[j].goal += ob;
                v[j].missed += oa;
                v[j].games += 1;
                if(oa < ob) {
                    v[j].points += 3;
                } else if(oa == ob) {
                    v[j].points += 1;
                }
            }
        }
        if(!founda) {
            v.push_back(team(a, oa, ob));
            if(oa > ob) {
                v[v.size() - 1].points += 3;
                v[v.size() - 1].games += 1;
            } else if(oa == ob) {
                v[v.size() - 1].points += 1;
                v[v.size() - 1].games += 1;
            }
        }
        if(!foundb) {
            v.push_back(team(b, ob, oa));
            if(oa < ob) {
                v[v.size() - 1].points += 3;
            } else if(oa == ob) {
                v[v.size() - 1].points += 1;
            }
        }
    }
    sort(v.begin(), v.end());
    int index;
    for(j = 0; j < v.size(); j++) {
        if(v[j].nome == "BERLAND") index = j;
    }
    if(v[index].points + 3 < v[0].points && v[index].points + 3 < v[1].points) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        string other;
        int pa = 0, pb = 0;
        for(j = 0; j < v.size(); j++) {
            if(v[j].nome == "BERLAND") {
                v[j].points += 3;
            }
            if(v[j].games == 1 && v[j].nome != "BERLAND") {
                other = v[j].nome;
            }
        }
        sort(v.begin(), v.end());
        while(1) {
          //  for(j = 0; j < v.size(); j++) {
         //       cout << v[j].nome << " " << v[j].points << " " << v[j].goal << " " << v[j].missed << endl;
        //    }
            if(v[0].nome == "BERLAND" || v[1].nome == "BERLAND") break;
            for(j = 0; j < v.size(); j++) {
                if(v[j].nome == "BERLAND") {
                    v[j].goal += 1;
                    pa += 1;
                }
                if(v[j].nome == other) {
                    v[j].missed += 1;
                }
            }
            sort(v.begin(), v.end());
        }
        if(pa == 0) pa = 1;
        cout << pa << ":" << pb << endl;
    }
    return 0;
}

