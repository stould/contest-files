#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int main(void) {
    while(cin >> N >> M) {
        vector<pair<int, int> > v;
        for(int i = 0; i < N; i++) {
            int tmp, sum = 0;
            for(int j = 0; j < M; j++) {
                cin >> tmp; sum += tmp;
            }
            v.push_back(make_pair(sum, i + 1));
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < 3; i++) {
            cout << v[i].second << endl;
        }
    }
    return 0;
}
