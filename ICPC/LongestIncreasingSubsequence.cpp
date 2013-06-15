#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

int i, j, k, l, a, b, mx, N, M;

int maze[650][650];

const int INF = 100000;

vector<int> store;

int lis(vector<int> A)
{
    int N = A.size(), c;
    set<int> s;
    set<int>::iterator k;
    for (c = 0; c < N; c++)
    {
        if (s.insert(A[c]).second)
        {
           k = s.find(A[c]);
           k++;
           if (k!=s.end())
              s.erase(k);
        }
    }
    return s.size();
}

int main(void) {
    while(cin >> N >> M) {
        if(N == 0 && M == 0) break;
        for(i = 0; i < N; i++) {
            for(j = 0; j < M; j++) {
                cin >> maze[i][j];
            }
        }
        for(i = 0; i < N; i++) {
            for(j = 0; j < M; j++) {
                for(k = i; k < N; k++) {
                    for(l = j; l < M; l++) {
                        store.clear();
                        mx = 0;
                        for(a = i; a <= k; a++) {
                            for(b = j; b <= l; b++) {
                                store.push_back(maze[a][b]);
                            }
                        }
                        mx = max(mx, lis(store));
                    }
                }
            }
        }
        cout << mx << endl;
    }
    return 0;
}
