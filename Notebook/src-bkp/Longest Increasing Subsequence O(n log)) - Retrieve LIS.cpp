#define STRICTLY_INCREASNG
vector<int> LongestIncreasingSubsequence(vector<int> v) {
    vector<pair<int, int> >  best;
    vector<int> dad(v.size(), -1);
    for (int i = 0; i < v.size(); i++) {
#ifdef STRICTLY_INCREASNG
        vector<pair<int, int> >  item = make_pair(v[i], 0);
        vector<pair<int, int> > ::iterator it = lower_bound(best.begin(), best.end(), item);
        item.second = i;
#else
        vector<pair<int, int> >  item = make_pair(v[i], i);
        vector<pair<int, int> > ::iterator it = upper_bound(best.begin(), best.end(), item);
#endif
        if (it == best.end()) {
            dad[i] = (best.size() == 0 ? -1 : best.back().second);
            best.push_back(item);
        } else {
            dad[i] = dad[it->second];
            *it = item;
        }
    }
    vector<int> ret;
    for (int i = best.back().second; i >= 0; i = dad[i])
        ret.push_back(v[i]);
    reverse(ret.begin(), ret.end());
    return ret;
}
