#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long Int;

const int MAXN = 100005;

const double PI = acos(-1.0);
const double EPS = 1e-7;

double Y1, Y2, YW, XB, YB, R;

//slope, coef
pair<double, double> line(double angle, double x, double y) {
    pair<double, double> ans;
    
    ans.first = tan(angle);
    ans.second = y - ans.first * x;
    
    return ans;
}

//in_y, abci
pair<double, pair<double, double> > opposite(pair<double, double> curr, double angle) {
    double xp = 0, yp = YW;    
    xp = (yp - curr.second) / curr.first;
	//cout << fixed << setprecision(5) << xp << " " << "\n";
    return make_pair(xp, line(PI/2.0 - angle, xp, yp));    
}

int main(void) {
    cin >> Y1 >> Y2 >> YW >> XB >> YB >> R;
    
    double l = 0.0, h = 90.0, m;
    double ans = -1;
    
    for (int x = 0; x < 10; x++) {
        m = (l + h) / 2.0;
        
        double in_rad = m * PI / 180.0;
        
        pair<double, double> fr = line(PI - (PI/2.0 - in_rad), XB, YB);        
        pair<double, pair<double, double> > of = opposite(fr, PI - (PI/2.0 - in_rad));        

        double abc = of.second.second;
        cout << fixed << setprecision(5) << m << " " << of.first << " " << of.second.second << "\n";
        
        if (abc - R >= Y1 && abc + R <= Y2) {
            ans = abc;
			if (abc - R - Y1 > Y2 - abc + R) {
				l = m;
			} else {
				h = m;
			}
        } else if (abc + R > Y2) {
            l = m;
        } else {
            h = m;
        }
    }
    
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}
