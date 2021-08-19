#include<bits/stdc++.h>
using namespace std;

// Sparse Table for range minimum query 
// T.C. O(1) 

/*	O(1) time complexity is only possible for those range queries
	that involves idempotent functions i.e. where A op A  = A
	like min, max, and, or but not any function like sum, xor.
	These other functions would be solved in logn time.
*/

const int NN = 1e7, k = 25; // k >= log2(NN)
int st[NN][k + 1];
int logs[NN];

void precompute(vector<int>& v) {
	
	int n = v.size();
	
	memset(st, 0, sizeof(st));
	
	for(int l = n - 1; l >= 0; l--) {
		for(int w = 0; w < 25; w++) {
			int r = l + (1 << w) - 1;
			
			if(r >= n) break;
			
			if(w == 0) st[l][w] = v[l];
			else st[l][w] = min(st[l][w - 1], st[l + (1 << (w - 1))][w - 1]);
		}
	}
}

void logCompute() {
	
	logs[1] = 0;
	for(int i = 2; i <= NN; i++) 
		logs[i] = logs[i / 2] + 1;
		
}

int query(int l, int r) {
	int w = r - l + 1;
	int power = logs[w];
	
	return min(st[l][power], st[r - (1 << power) + 1][power]);
}

int main() {
	
	int n, q;
	cin >> n >> q;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	
	precompute(v);         // O(nlogn)
	logCompute();		  // O(n)
	
	while(q--) {
		int l, r;
		cin >> l >> r;
		
		// O(1)
		cout << query(l, r) << endl;
	}
	
	return 0;
}
