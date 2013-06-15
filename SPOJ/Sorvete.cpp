#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int i, j, p, s, f, t, test = 1;
pair<int, int> m[5050];

int main(void) {

    while(cin >> p >> s) {
        if(!p && !s) break;

        for(i = 0; i < s; i++) {
            cin >> f >> t;
            m[i] = make_pair(f, t);
        }
        sort(m, m + s);
        cout << "Teste " << (test++) << endl;
        for(i = 0; i < s; i++) {
            int start = m[i].first;
            int end = m[i].second;
            for(j = i; j < s; j++) {
                if(end >= m[j].first) {
                    if(m[j].second > end) {
                        end = m[j].second;
                    }
                } else {
                    break;
                }
            }
            i = j - 1;
            cout << start << " " << end << endl;
        }
        cout << endl;
    }
    return 0;
}
