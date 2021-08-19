#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

// Refer to Hackerearth article 

// Finding total number of hamiltonian paths
void findHamPaths(int n) {

	int limit = 1<<n;

	int dp[n][1<<n];
	memset(dp, 0, sizeof(dp));
	
	for(int i = 0; i < n; i++) {
		dp[i][1<<i] = 1;
	}

	// mask --> subsets of graph, v --> vertex, nb --> neighbor of v
	for(int mask = 0; mask < limit; mask++) {
		for(int v = 0; v < n; v++) {
			if(mask & (1<<v)) {
				for(int nb = 0; nb < n; nb++) {
					if(nb != v and (mask & (1<<nb)) and adj[v][nb]) {
						dp[v][mask] += dp[nb][mask ^ (1<<v)];
					}
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += dp[i][limit - 1];
	}

	cout << ans << endl;
}

int main() {
	
	int n, m;
	cin >> n >> m;

	adj.resize(n, vector<int> (n, 0));

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x - 1][y - 1] = adj[y - 1][x - 1] = 1;
	}

	findHamPaths(n);
}


