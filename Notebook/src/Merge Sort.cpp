//Merge-Sort O(N log N)
vector<int> merge(vector<int>& b, vector<int>& c) {
	vector<int> a;

	while(!b.empty() && !c.empty()) {
		if(*b.begin() < *c.begin()) {
			a.push_back(*b.begin());
			b.erase(b.begin());
		} else if(*b.begin() > *c.begin()) {
			a.push_back(*c.begin());
			c.erase(c.begin());
		} else {
			a.pb(*b.begin());
			a.pb(*c.begin());
			b.erase(b.begin());
			c.erase(c.begin());
		}
	}
	while(!b.empty()) { a.pb(*b.begin()); b.erase(b.begin()); }
	while(!c.empty()) { a.pb(*c.begin()); c.erase(c.begin()); }
	return a;
}

vector<int> mergeSort(vector<int>& a) {
	if(sz(a) <= 1) {
		return a;
	}
	vector<int> b;
	vector<int> c;

	for(int i = 0; i < sz(a) / 2; i++) {
		b.pb(a[i]);
	}
	for(int i = sz(a) / 2; i < sz(a); i++) {
		c.pb(a[i]);
	}
	vector<int> sb = mergeSort(b);
	vector<int> sc = mergeSort(c);
	return merge(sb, sc);
}
