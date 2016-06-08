#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1010;
const int INF = 1061109567;

int N, M;
string S[MAXN];
int dist[MAXN][MAXN][5];
map<char, int> rot[5];
map<char, vector<pair<int, int> > > dx;

void build() {
    rot[0]['+'] = '+';
    rot[1]['+'] = '+';
    rot[2]['+'] = '+';
    rot[3]['+'] = '+';
    
    dx['+'] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    rot[0]['-'] = '-';
    rot[1]['-'] = '|';
    rot[2]['-'] = '-';
    rot[3]['-'] = '|';

    dx['-'] = {{0, -1}, {0, 1}};

    rot[0]['|'] = '|';
    rot[1]['|'] = '-';
    rot[2]['|'] = '|';
    rot[3]['|'] = '-';

    dx['|'] = {{-1, 0}, {1, 0}};

    rot[0]['^'] = '^';
    rot[1]['^'] = '>';
    rot[2]['^'] = 'v';
    rot[3]['^'] = '<';

    dx['^'] = {{-1, 0}};

    rot[0]['>'] = '>';
    rot[1]['>'] = 'v';
    rot[2]['>'] = '<';
    rot[3]['>'] = '^';

    dx['>'] = {{0, 1}};

    rot[0]['v'] = 'v';
    rot[1]['v'] = '<';
    rot[2]['v'] = '^';
    rot[3]['v'] = '>';

    dx['v'] = {{1, 0}};

    rot[0]['<'] = '<';
    rot[1]['<'] = '^';
    rot[2]['<'] = '>';
    rot[3]['<'] = 'v';

    dx['<'] = {{0, -1}};

    rot[0]['L'] = 'L';
    rot[1]['L'] = 'U';
    rot[2]['L'] = 'R';
    rot[3]['L'] = 'D';

    dx['L'] = {{-1, 0}, {0, 1}, {1, 0}};

    rot[0]['R'] = 'R';
    rot[1]['R'] = 'D';
    rot[2]['R'] = 'L';
    rot[3]['R'] = 'U';

    dx['R'] = {{-1, 0}, {0, -1}, {1, 0}};

    rot[0]['U'] = 'U';
    rot[1]['U'] = 'R';
    rot[2]['U'] = 'D';
    rot[3]['U'] = 'L';

    dx['U'] = {{1, 0}, {0, -1}, {0, 1}};

    rot[0]['D'] = 'D';
    rot[1]['D'] = 'L';
    rot[2]['D'] = 'U';
    rot[3]['D'] = 'R';

    dx['D'] = {{-1, 0}, {0, -1}, {1, 0}};
}

int main(void) {
    build();
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int si, sj, ei, ej;

    cin >> si >> sj >> ei >> ej;

    si -= 1;
    sj -= 1;
    ei -= 1;
    ej -= 1;
    
    memset(dist, 63, sizeof(dist));

    priority_queue<pair<pair<int, int>, pair<int, int> > > q;

    for (int x = 0; x <= 3; x++) {
        dist[si][sj][x] = x;
        q.push(make_pair(make_pair(-x, x), make_pair(si, sj)));
    }
        
    while (!q.empty()) {
        int ds = -q.top().first.first;
        int curr_rot = q.top().first.second;
        int ci = q.top().second.first;
        int cj = q.top().second.second;
        q.pop();
        
        if (dist[ci][cj][curr_rot] < ds) continue;

        if (ci == ei && cj == ej) break;
        
        if (dist[ci][ci][(curr_rot + 1) % 4] > dist[ci][cj][curr_rot] + 1) {
            dist[ci][cj][(curr_rot + 1) % 4] = dist[ci][cj][curr_rot] + 1;
            q.push(make_pair(make_pair(-dist[ci][cj][(curr_rot + 1) % 4], (curr_rot + 1) % 4), make_pair(ci, cj)));
        }
        
        char pos = rot[curr_rot][S[ci][cj]];
        
        for (int i = 0; i < (int) dx[pos].size(); i++) {
            int ni = ci + dx[pos][i].first;
            int nj = cj + dx[pos][i].second;
            
            if (ni >= 0 && nj >= 0 && ni < N && nj < M) {
                char next_pos = rot[curr_rot][S[ni][nj]];
                
                for (int j = 0; j < (int) dx[next_pos].size(); j++) {
                    int pi = ni + dx[next_pos][j].first;
                    int pj = nj + dx[next_pos][j].second;
                    
                    if (pi >= 0 && pj >= 0 && pi < N && pj < M) {
                        if (pi == ci && pj == cj) {
                            if (dist[ni][nj][curr_rot] > dist[ci][cj][curr_rot] + 1) {
                                dist[ni][nj][curr_rot] = dist[ci][cj][curr_rot] + 1;
                                q.push(make_pair(make_pair(-dist[ni][nj][curr_rot], curr_rot), make_pair(ni, nj)));
                            }
                        }
                    }
                }
            }
        }    
    }

    int best = INF;

    for (int i = 0; i < 4; i++) {
        chmin(best, dist[ei][ej][i]);
    }

    if (best == INF) {
        best = -1;
    }

    cout << best << "\n";
    return 0;
}
