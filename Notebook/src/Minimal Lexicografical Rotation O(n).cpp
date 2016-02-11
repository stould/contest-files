string min_lex (string s){
	int n = s.size();
	s = s + s;
	int mini = 0, p = 1, l = 0;
	
	while(p < n && mini + l + 1 < n)
		if(s[mini + l] == s[p + l])
			l++;
		else if(s[mini + l] < s[p + l]){
			p = p + l + 1;
			l = 0;
		}
		else if(s[mini + l] > s[p + l]){
			mini = max(mini + l + 1, p);
			p = mini + 1;
			l = 0;
		}
	s = s.substr(mini, n);
	return s;
}

