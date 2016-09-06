int N, B;
pair<int, int> P[100005];

bool cmp(pair<int, int> a, pair<int, int> b) {
    double valA = a.second == 0 ? INF : a.first / (double) a.second;
    double valB = b.second == 0 ? INF : b.first / (double) b.second;

    return valA < valB;
}

//value
for (int i = 0; i < N; i++) {
    cin >> P[i].first;
 }
//price
for (int i = 0; i < N; i++) {        
    cin >> P[i].second;
 }

sort(P, P + N, cmp);

int ans = 0;

for (int i = N - 1; i >= 0; i--) {
    if (P[i].second <= B) {
        ans += P[i].first;
        B -= P[i].second;
    } else {
        ans += floor((B * P[i].first) / (double) P[i].second);
        B = 0;
    }
 }
