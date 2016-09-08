#include <queue>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 205;
const double PI = acos(-1);
const int INF = 100100100;
const double EPS = 1e-6;

int J, R, D;
long long X[MAXN], Y[MAXN];
vector<int> G[MAXN];
double dist[MAXN * MAXN], len[MAXN][MAXN], angle[MAXN][MAXN][MAXN];
priority_queue<pair<double, int> > q;

double DEG_to_RAD(double theta) {    
    return theta*PI/180.;
}

double RAD_to_DEG(double theta) {
    return theta*180. / PI;
}

struct Vector {
    double x, y;

    Vector() {}
    Vector(double x, double y): x(x), y(y) {}

    double mod() { return hypot(x, y); }

    double angle(Vector v) {
        return RAD_to_DEG(acos(dot(v) / (mod() * v.mod())));
    }

    double dot(Vector v) {
        return (x * v.x + y * v.y);
    }
    double cross(Vector v) {
        return (x * v.y - y * v.x);
    }
};


double getAngle(int a, int b, int c) {
    if (a == b || a == c || b == c) return 0;

    double xa = X[a] - X[b];
    double ya = Y[a] - Y[b];

    double xb = X[b] - X[c];
    double yb = Y[b] - Y[c];
    
    Vector va(xa, ya);
    Vector vb(xb, yb);

    //return RAD_to_DEG(acos((xa * xb + ya * yb) / hypot(xa, ya) * hypot(xb, yb)));
    return va.angle(vb);
}

double getDist(int a, int b) {
    return sqrt((X[a] - X[b]) * (X[a] - X[b]) + (Y[a] - Y[b]) * (Y[a] - Y[b]));
}

bool func(int rt, double largest) {
    while (!q.empty()) q.pop();
    
    q.push({0, rt});
    
    for (int i = 0; i <= J * J; i++) {
        dist[i] = INF;
    }
    
    dist[rt] = 0;

    while (!q.empty()) {
        double ds = -q.top().first;
        int id  = q.top().second;
        int now = q.top().second % J;
        int pre = q.top().second / J;
        q.pop();

        if (ds > EPS + dist[id]) continue;
        
        if (now == J - 1) {      
            return true;
        }

        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i];
            double dst = dist[id] + len[now][next];
            double ang = angle[pre][now][next];

            if (ang > largest) continue;
            if (dst - EPS > D) continue;
            
            int next_id = now * J + next;
            
            if (dist[next_id] > dst) {                
                dist[next_id] = dst;
                q.push(make_pair(-dst, next_id));
            }
        }
    }
  
    return false;
}

int main() {
    scanf("%d%d%d", &J, &R, &D);

    for (int i = 0; i < J; i++) {
        scanf("%lld%lld", &X[i], &Y[i]);
    }
    
    for (int i = 0; i < R; i++) {
        int a, b;

        scanf("%d%d", &a, &b);

        a -= 1;
        b -= 1;

        len[a][b] = getDist(a, b);
        G[a].push_back(b);    
    }

    for (int i = 1; i <= J; i++) {
        for (int j = 0; j < (int) G[i].size(); j++) {
            int a = G[i][j];
            
            for (int k = 0; k < (int) G[a].size(); k++) {
                angle[i][a][G[a][k]] = getAngle(i, a, G[a][k]);
            }
        }
    }

    double l = 0.0, h = 180;
    double ans = INF;
    
    for (int i = 0; i < 80; i++) {
        double m = (l + h) / 2;
        
        bool now = func(0, m);

        if (now) {
            ans = m;
            h = m;
        } else {
            l = m;
        }
    }
    //cout << fixed << setprecision(8) << ans << "\n";
    if (ans + EPS <= INF) {
        printf("%.8lf\n", ans);
    } else {
        puts("Impossible\n");
    }
    return 0;
}
