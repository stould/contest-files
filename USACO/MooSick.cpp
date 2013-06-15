#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

template<typename T> T abs(T a) { return a > 0 ? a : -a; }

int main() {
    freopen("MooSick/I.5", "r", stdin);
    int N, C, i, j, valids = 0;
    vector<int> startPoint;

    scanf("%d", &N);
    vector<int> song(N);

    for(i = 0; i < N; i++) {
        scanf("%d", &song[i]);
    }

    scanf("%d", &C);
    vector<int> prob(C);

    for(i = 0; i < C; i++) {
        scanf("%d", &prob[i]);
    }

    sort(prob.begin(), prob.end());

    for(i = 0; i < N - C + 1; i++) {
        vector<int> tmp;
        for(j = i; j < i + C; j++) {
            tmp.push_back(song[j]);
        }
        sort(tmp.begin(), tmp.end());
        bool ok = true;

        for(j = 1; j < C; j++) {
            if(abs(tmp[j] - tmp[j - 1]) != abs(prob[j] - prob[j - 1])) {
                ok = false;
                break;
            }
        }
        if(ok) {
            valids++;
            startPoint.push_back(i + 1);
        }
    }
    printf("%d\n", valids);
    for(i = 0; i < startPoint.size(); i++) {
        printf("%d\n", startPoint[i]);
    }
    return 0;
}
