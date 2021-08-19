/* Given an undirected graph containing N vertices and M edges, find all the articulation points and all the bridges in the graph. */ 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> disc, low;
vector<bool> vis;

vector<int> apoints;
vector<pair<int,int>> bridges;
int tme = 1;

// T.C. = O(V + E)
void dfs(int node, int par) {

	vis[node] = true;
	disc[node] = low[node] = tme++;

	int child = 0;
	for(int x: adj[node]) {
		if(!vis[x]) {
			child++;
			dfs(x, node);

			low[node] = min(low[node], low[x]);

			// node is root 
			if(par == -1 and child > 1) {
				apoints.push_back(node);
			} else if(par != -1 and low[x] >= disc[node]) {
				apoints.push_back(node);
			}

			// For bridges
			if(low[x] > disc[node]) {
				bridges.push_back({node, x});
			}

		} else if(par != x) {
			low[node] = min(low[node], disc[x]);
		}
	}
}

int main() {
	
	int n, m;
	cin >> n >> m;

	adj.assign(n, vector<int> ());
	disc.assign(n, INT_MAX);
	low.assign(n, INT_MAX);
	
	vis.assign(n, false);

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(0, -1);

	sort(apoints.begin(), apoints.end());
	cout << apoints.size() << endl;
	for(int x: apoints) cout << x << " ";
	cout << endl;

	auto compare = [&](auto a, auto b){
		return a.first < b.first || (a.first == b.first && a.second < b.second);
	};
	sort(bridges.begin(), bridges.end(), compare);

	cout << bridges.size() << endl;
	for(auto x: bridges) cout << x.first << " " << x.second << endl;

	return 0;
}


