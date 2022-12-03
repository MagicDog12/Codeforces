#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
 
struct segtree{
	pair<int, int> st[MAX << 1];
 
	int fpb(int a, int b){
		if(a == 0) return b;
		else if(b == 0) return a;
		else return fpb(b, a % b);
	}
 
	pair<int, int> merge(pair<int, int> a, pair<int, int> b){
		int fp = fpb(a.first, b.first);
		pair<int, int> ans = {fp, 0};
		if(a.first == fp) ans.second += a.second;
		if(b.first == fp) ans.second += b.second;
		return ans;
	}
 
	void update(int p, int v){
		for(st[p += MAX] = {v, 1}, p >>= 1; p > 0; p >>= 1) st[p] = merge(st[p << 1], st[p << 1|1]);
	}
 
	pair<int, int> query(int l, int r){
		pair<int, int> res = {0, 0};
		for(l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = merge(res, st[l++]);
			if(r & 1) res = merge(res, st[--r]);
		}
		return res;
	}
} S;
 
int main(){
    int N, Q, s[MAX];
 
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s[i];
		S.update(i, s[i]);
	}
 
	cin >> Q;
	for(int j = 0; j < Q; j++){
		int l, r; cin >> l >> r; l--, r--;
		cout << (r - l + 1 - S.query(l, r).second) << endl;
	}
    return 0;
}