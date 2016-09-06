sort(p, p + N);
		
int l = 0;
int r = 0;

vector<pair<int, int> > ans;

for (int i = 0; i < N; i++) {
    if (r >= M) break;
    if (p[i].first <= l) {
        int pos = i;
				
        r = p[i].second;
				
        while (i < N && p[i].first <= l) {
            if (p[i].second > r) {
                pos = i;
                r = p[i].second;
            }
            i++;					
        }
        ans.push_back(p[pos]);
        
        l = r;
        i--;
    }
 }

if (r < M) {
    fail = true;
 }
