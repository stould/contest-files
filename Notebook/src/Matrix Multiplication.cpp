vector<vector<int> > multiply(vector<vector<int> > a, vector<vector<int> > b) {
	vector<vector<int> > res(c, vector<int>(c));
	for(int i = 0; i < c; i++) {
		for(int j = 0; j < c; j++) {
			int sum = 0;
			for (int k = 0; k < c; k++) {
				sum |= a[i][k] & b[k][j];
			}
			res[i][j] = sum;
		}
	}
	return res;
}

vector<vector<int> > binPow(vector<vector<int> > a, int n) {
	if (n == 1) {
		return a;
	} else if ((n & 1) != 0) {
		return multiply(a, binPow(a, n - 1));
	} else {
		vector<vector<int> > b = binPow(a, n / 2);
		return multiply(b, b);
	}
}

