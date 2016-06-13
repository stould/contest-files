#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30030;

int T, N;
pair<double, double> P[MAXN];

double trap(pair<double, double> a, pair<double, double> b) {
    return (0.5*(b.first - a.first)*(b.second + a.second));
}

double area(vector<pair<double, double> > vin) {
    int n = vin.size();
  
    sort(vin.begin(), vin.end());
    double ans = 0;
  
    do {
        double ret = 0.0;
        for(int i = 0; i < n; i++) {
            ret += trap(vin[i], vin[(i+1)%n]);
        }
        ans = max(ans, fabs(ret));
    } while (next_permutation(vin.begin(), vin.end()));
  
    return fabs(ans);
}

double tryA(int base) {
    vector<pair<double, double> > vs;
  
    for (int i = 0; i < base; i++) {
        vs.push_back(P[i]);
    }
  
    for (int i = base; i < N; i++) {
        vector<pair<double, double> > buff = vs;
        double curr_area = area(buff);
        double best = 0;
        int id = -1;

        for (int j = 0; j < base; j++) {
            swap(buff[j], P[i]);
            if (area(buff) >= curr_area) {
                curr_area = area(buff);
                id = j;
            }    
            swap(buff[j], P[i]);
        }    
        if (id != -1) {
            vs = buff;
            buff[id] = P[i];
        }
        vs = buff;
    }
    return area(vs);
}

int main() {
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> P[i].first >> P[i].second;
        }

        sort(P, P + N);

        double ans = tryA(3);

        cout << fixed << setprecision(1) << ans << "\n";
    }
    return 0;
}
