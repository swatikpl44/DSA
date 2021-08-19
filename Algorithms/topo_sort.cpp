#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj;
	adj.assign(n + 1, vector<int> ());

	vector<int> indegree(n + 1, 0);
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		indegree[y]++;
	}

	// queue can be used - T.C = O(V + E)
	// but if lexicographically smallest ordering is needed, use priority queue - T.C = O(V + ElogV)
	priority_queue<int, vector<int>, greater<int>> qe;
	for(int i = 1; i <= n; i++) {
		if(indegree[i] == 0) qe.push(i);
	}

	vector<int> ans;
	while(!qe.empty()) {

		int f = qe.top();
		qe.pop();

		ans.push_back(f);
		for(int x: adj[f]) {
			indegree[x]--;

			if(indegree[x] == 0) qe.push(x);
		}
	}

	for(int x: ans) cout << x << " ";
	return 0;
}



