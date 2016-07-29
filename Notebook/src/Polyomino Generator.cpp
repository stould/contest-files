int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pair<int, int> > q[1000010];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (abs(a.first) != abs(b.first)) {
        return abs(a.first) < abs(b.first);
    } else {
        return abs(a.second) < abs(b.second);
    }		  
}

uInt getHash(vector<pair<int, int> > arg) {
    uInt ans = 10000007ULL;

    for (int i = 0; i < (int) arg.size(); i++) {
        ans = ans * 1234567891 + abs(arg[i].first) + 1074178147781ULL;
        ans = ans * 1234567891 + abs(arg[i].second) + 1074178147781ULL;
    }
	
    return ans;
}

vector<vector<pair<int, int> > > generatePoly(int len) {
    vector<vector<pair<int, int> > > ans;

    int qf = 0, qt = 0;

    vector<pair<int, int> > base;
    base.push_back(make_pair(0, 0));
    q[qt++] = base;
	
    map<uInt, bool> vis;
	
    for ( ; qf < qt; ) {

        vector<pair<int, int> > now = q[qf++];

        if (len == (int) now.size()) {
            ans.push_back(now);
            /*
            for (int i = 0; i < (int) now.size(); i++) {
                cout << now[i].first << " " << now[i].second << " ";
            }
            cout << endl;
            */
            continue;
        }
		
        for (int i = 0; i < (int) now.size(); i++) {
            for (int j = 0; j < 4; j++) {
                int now_i = now[i].first + dx[j];
                int now_j = now[i].second + dy[j];

                pair<int, int> curr = make_pair(now_i, now_j);
                
                if (find(now.begin(), now.end(), curr) == now.end()) {
                    vector<pair<int, int> > poss = now;
					
                    poss.push_back(curr);

                    int smx = INF;
                    int smy = INF;
                    
                    for (int k = 0; k < (int) poss.size(); k++) {
                        chmin(smx, poss[k].first);
                        chmin(smy, poss[k].second);
                    }

                    smx = abs(smx);
                    smy = abs(smy);
                    
                    for (int k = 0; k < (int) poss.size(); k++) {
                        poss[k].first += smx;
                        poss[k].second += smy;
                    }

                    sort(poss.begin(), poss.end());
                    
                    uInt c_hash = getHash(poss);
					
                    if (vis[c_hash] == false) {
                        vis[c_hash] = true;
                        q[qt++] = poss;
                    }
                }														   
            }
        }
    }

    return ans;
}
