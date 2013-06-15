#include <iostream>

using namespace std;

int n, m, l = 0;
string maze[110];

int main(void) {
    cin >> n >> m;
    pair<int, int> p[3];

    for(int i = 0; i < n; i++) {
        cin >> maze[i];
        for(int j = 0; j < n; j++) {
            if(maze[i][j] == '*') {
                p[l++] = make_pair(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == '*') {
                bool r = false, d = false;
                int k, l;
                for(k = i + 1; k < n; k++) {
                    if(maze[k][j] == '*') { d = true; break; }
                }
                for(l = j + 1; l < m; l++) {
                    if(maze[i][l] == '*') { r = true; break; }
                }
                if(r && d) {
                    cout << k << " " << l << endl;
                } else {
                    if(r && !d) {
                        for(k = i + 1; k < n; k++) {
                            if(maze[k][l] == '*') {
                                break;
                            }
                        }
                        cout << (k - i) << " " << l << endl;
                    }
                }
            }
        }
    }

    return 0;
}
