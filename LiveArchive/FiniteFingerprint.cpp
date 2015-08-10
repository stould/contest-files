#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long hash;

const int MAXN = 1010;

const hash BASE = 31ULL;

int N;
map<char, int> charMemo;
string S[MAXN];
hash h[MAXN], pw[MAXN], C[MAXN];

hash getHash(int l, int r) {
    hash ans = (h[l] - h[r + 1]) * pw[l] + C[r - l + 1];
    return ans;
}

void build() {
    int pos = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        charMemo[c] = pos++;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        charMemo[c] = pos++;
    }
    for (char c = '0'; c <= '9'; c++) {
        charMemo[c] = pos++;
    }
    charMemo['+'] = pos++;
    charMemo['/'] = pos++;
}

string charToBin(char c) {
    string ans = "";
   
    int val = charMemo[c];

   
    while (val > 0) {
        ans += '0' + (val % 2);
        val /= 2;
    }
   
    while (ans.size() < 6) {
        ans = "0" + ans;
    }   
   
    return ans;
}

string convToBin(string& arg) {
    string ans = "";
   
    for (int i = 0; i < (int) arg.size(); i++) {
        ans += charToBin(arg[i]);
    }   
       
    return ans;
}

bool isLess(int st_a, int st_b, int id, int len) {
    int l = 0, h = len, m;
    int pos = len - 1;

    while (l <= h) {
        m = (l + h) / 2;

//        cout << S[id].substr(st_a, m) << " " << S[id].substr(st_b, m) << " => " << getHash(st_a, st_a + m) << " " << getHash(st_b, st_b + m) << " " << pos << "\n";
       
        if (getHash(st_a, st_a + m) == getHash(st_b, st_b + m)) {
            l = m + 1;
        } else {           
            pos = min(pos, m);
            h = m - 1;
        }
    }

    cout << S[id].substr(st_a, len) << " " << S[id].substr(st_b, len) << " " << pos << " " << S[id][st_a + pos] << " " << S[id][st_b + pos] << " => " << getHash(st_a, st_a + 1) << " " << getHash(st_b, st_b +1) << "\n";

    return S[id][st_a + pos] < S[id][st_b + pos];
}

string smallRot(int id) {
    S[id] = S[id] + S[id];
   
    int len = (int) S[id].size();
    int ans_l = 0;
           
    h[len] = 1;   
   
    for (int i = len - 1; i >= 0; i--) {
        h[i] = h[i + 1] * BASE + (S[id][i] - '0' + 1);
		cout << h[i] << " ";
    }
	
    for (int i = 0; i + (len / 2) < len; i++) {
//    cout << i << " " << i + len / 2 << " " << S[id].substr(i, len / 2) << " " << getHash(i, i + (len / 2)) << "\n";
//        getHash(i, i + (len / 2));
        if (isLess(i, ans_l, id, len / 2)) {
            ans_l = i;
        }               
    }
	
    //cout << arg.substr(0, len) << " " << arg.substr(ans_l, len) << "\n";
    return S[id].substr(ans_l, len / 2);
}

bool compare(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        return a < b;
    }
}

int main() {
    int test = 1;
   
    pw[0] = 1ULL;
    C[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pw[i] = pw[i - 1] * BASE;
        C[i] = C[i - 1] * 29ULL;
    }
   
    build();
   
    while (cin >> N && N != 0) {
        map<string, vector<int> > mp;
        map<string, vector<int> >::iterator it;
       
        for (int i = 0; i < N; i++) {
            cin >> S[i];
            S[i] = convToBin(S[i]);
           
            string best = smallRot(i);           
            cout << best << "\n";
            mp[best].push_back(i + 1);
        }
       
        vector<vector<int> > ans;
       
        for (it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }       
       
        sort(ans.begin(), ans.end(), compare);
       
        cout << "Case " << test++ << ":\n";
       
        for (int i = 0; i < (int) ans.size(); i++) {
            for (int j = 0; j < (int) ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
       
    return 0;
}
