#include<bits/stdc++.h>
using namespace std;
#define pb push_back

// Kosaraju algorithm
// To find the strongly connected components of a graph

// This is a 3 step process.
// The first step is to traverse the graph using DFS and then push the nodes in stack.
// The second step is to find transpose of the graph, that is, reverse all the edges in the graph.
// The third step is to pop nodes one by one from stack and make DFS calls to find the nodes in a strongly connected component.

// Time Complexity = O(v + e)

int n;
vector<vector<int>> adj, rev;

void DFS1(int i, vector<bool>& visited, vector<int>& todo) {
	
	visited[i]=true;
	
	for(int j: adj[i])
		if(visited[j] == false)
			DFS1(j, visited, todo);

	todo.pb(i);
}

void reverse() {
	
	for(int i = 0; i < n; i++) {
		for(int j: adj[i])
			rev[j].pb(i);
	}
}

void DFS2(int i, vector<bool>& visited, vector<int>& component) {
	
	cout << i << " ";
	component.pb(i);
	visited[i] = true;
	
	for(int j: rev[i])
		if(!visited[j])
			DFS2(j, visited, component);
}

void findSCCs() {
	vector<int> todo;

	vector<bool> visited(n, false);
	
	for(int i = 0; i < n; i++)
		if(!visited[i])
			DFS1(i, visited, todo);

	reverse();

	for(int i = 0; i < n; i++)
		visited[i] = false;

	cout << "Strongly Connected Components are:\n";

	vector<int> roots(n, -1);
	
	reverse(todo.begin(), todo.end());
	for(int curr: todo) {
		
		if(visited[curr] == false) {
			
			vector<int> component;
			DFS2(curr, visited, component);
			
			int root = component.front();
        	for (auto u : component) roots[u] = root;
        	//root_nodes.push_back(root);

        	component.clear();
        
			cout<<"\n";
		}
	}
	
	// Condensation of graph
	unordered_set<int> adj_scc[n];
	for (int v = 0; v < n; v++) {
	
    	for (auto u : adj[v]) {
        	int root_v = roots[v], root_u = roots[u];

        	if (root_u != root_v)
            	adj_scc[root_v].insert(root_u);
    	}
    	
    }
    
    for(int i = 0; i < n; i++) {
    	for(int j: adj_scc[i]) {
    		cout << i << " " << j << endl;
		}
	}
}

int main() {
	
	int m;
	cin >> n >> m;
	
	adj.assign(n + 1, vector<int> ());
	rev.assign(n + 1, vector<int> ());
	
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	
	findSCCs();
	return 0;
}
