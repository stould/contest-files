struct node {
	int v;	
	node *l;
	node *r;

	node() {
		v = -1;
		l = NULL;
		r = NULL;
	}

	node(int vv) {
		v = vv;
		l = NULL;
		r = NULL;
	}
};

void insert(node** n, int v) {
	if ((*n) == NULL) {
		*n = new node(v);
	} else {
		if ((*n)->v > v) {
			insert(&(*n)->l, v);
		} else {
			insert(&(*n)->r, v);
		}
	}
}

vector<int> buff;

void prefix(node** n) {
	if ((*n) != NULL) {
		buff.push_back((*n)->v);
		if ((*n)->l != NULL) prefix(&(*n)->l);
		if ((*n)->r != NULL) prefix(&(*n)->r);
	}
}

void infix(node** n) {
	if ((*n) != NULL) {
		if ((*n)->l != NULL) infix(&(*n)->l);
		buff.push_back((*n)->v);
		if ((*n)->r != NULL) infix(&(*n)->r);
	}
}

void postfix(node** n) {
	if ((*n) != NULL) {
		if ((*n)->l != NULL) postfix(&(*n)->l);
		if ((*n)->r != NULL) postfix(&(*n)->r);
		buff.push_back((*n)->v);
	}
}

void clear(node** n) {
	if ((*n) != NULL) {
		if ((*n)->l != NULL) clear(&(*n)->l);
		if ((*n)->r != NULL) clear(&(*n)->r);
		delete (*n);
	}
}
