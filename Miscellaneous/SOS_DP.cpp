#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

// SOS DP: https://codeforces.com/blog/entry/45223

// We have an array A of N elements. We will be asked Q queries. each query is in the form of a single integer, X,
// and we have to tell whether there exists an index i in the array such that the bitwise AND of A[i] and X equals 0. 
// If such an index exists print YES, otherwise print NO.

// Constraints : 1<=N<=1e5, 1<=Q<=1e5, 1<=A[i]<=1e5

int main() {
	
	int n;
	cin >> n;
	
	vector<int> a(n), dp(1<<17);
	rep(i, n) {
		cin >> a[i];
		dp[~a[i] & ((1<<17) - 1)] = 1;
	}
	
	for(int i = 0; i < 17; i++) {
		for(int mask = 0; mask < (1<<17); mask++) {
			if(mask & (1<<i)) {
				dp[mask ^ (1<<i)] = max(dp[mask], dp[mask ^ (1<<i)]);
			}
		}
	}
	
	int q;
	cin >> q;
	
	while(q--) {
		int x;
		cin >> x;
		
		cout << (dp[x] ? "YES\n" : "NO\n");
	}
	
	return 0;
}
