#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;

int N, K;

set<string> mem;
string s;

int main(void) {
    while(scanf("%d%d", &N, &K)) {
        if(N == 0 && K == 0) break;
        mem.clear();
        for(int i = 0; i < (1 << K); i++) {
            int tmp = 0, ct = 0;
            s.clear();
            for(int j = 0; j < K; j++) if(i & (1 << j)) {
                tmp += j;
                ct += 1;
                s += (char) j +  '0';
            }
            cout << s << endl;
            if(tmp == K && ct == N) {
                mem.insert(s);
            }
        }
        cout << mem.size() << endl;
    }
    return 0;
}
