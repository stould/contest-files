#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Gap {
    int start, end;

    Gap(){}

    Gap(int s, int e) {
        start = s;
        end = e;
    }

    int size() {
        return end - start - 1;
    }

    bool operator<(const Gap& g) const {
        return (end - start - 1) > (g.end - g.start - 1);
    }
};

int M, S, C, len = 0, ms[300];
Gap p[300];

int main(void) {
    freopen("barn1.in", "r", stdin);
    cin >> M >> S >> C;
    for(int i = 0; i < C; i++) {
        cin >> ms[i];
    }
    sort(ms, ms + C);
    for(int i = 1; i < C; i++) {
        if(ms[i] - ms[i - 1] > 1) {
            p[len++] = Gap(ms[i - 1], ms[i]);
        }
    }
    sort(p, p + len);
    int base = 0, spent = C;
    int b = len + 1;
    for(int i = 0; i < len; i++) {
        cout << p[i].start << " " << p[i].end << endl;
    }
//    while(b > M) {
//        spent += p[base].size();
//        base += 1;
//        cout << p[base].start << " " << p[base].end << endl;
//        b--;
//    }
    cout << spent << endl;
    return 0;
}
