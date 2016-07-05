const int INF = 1000 * 1000 * 1000;

int n, m;
vector <vector <int>> t;

void init(int _n, int _m) {
    n = _n;
    m = _m;
    for(int i = 0; i < n; i++) {
        t.push_back(vector<int>(m, 0));
    }
}

int sum(int x, int y) {
    int result = 0;
    for (int i = x; i> = 0; i = (i & (i +1)) - 1) {
        for (int j = y; j> = 0; j = (j & (j +1)) - 1) {
            result += t[i][j];
        }
    }
    return result;
}

void inc (int x, int y, int delta) {
    for (int i = x; i <n; i = (i | (i +1))) {
        for (int j = y; j <m; j = (j | (j +1))) {
            t[i][j] += delta;
        }
    }
}

void update(int x, int y, int new_value) {
    for (int i = x; i> = 0; i = (i & (i +1)) - 1) {
        for (int j = y; j> = 0; j = (j & (j +1)) - 1) {
            t[i][j] = new_value;
        }
    }
}

// sum[(r1, c1), (r2, c2)]
int sum(int[][] t, int r1, int c1, int r2, int c2) {
	return sum(t, r2, c2) - sum(t, r1 - 1, c2) - sum(t, r2, c1 - 1) + sum(t, r1 - 1, c1 - 1);
}
