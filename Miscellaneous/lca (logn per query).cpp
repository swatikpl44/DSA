#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int NN = 1e5;
vector<int> tree[NN];
const int level = 18;                  // log(NN)base2 approx 18

// DFS to calculate the depth of each node and their first parent
int depth[NN];
int parent[NN][level];
void dfs(int node, int par)
{
	depth[node] = depth[par] + 1;
	parent[node][0] = par;
	for(int child:tree[node])
	{
		if(child!=par) dfs(child,node);
	}
}

// To precompute the parents for each node (parent at 2^i height)
// because any height can be reached using sum of powers of 2
// O(nlogn)
void precompute(int n)
{
	for(int i=1;i<level;i++)
	{
		for(int node=1;node<=n;node++)
		{
			// To get a parent of a node at height h from node itself, 
			// find the parent at height h/2 and find parent at height h/2 of this founded parent
			// height h --> 2^i
			// height h/2 --> 2^(i-1)  
			if(parent[node][i-1]!=-1)
			parent[node][i] = parent[parent[node][i-1]][i-1];        
		}
	}
}

int lca(int u, int v)
{
    if(depth[u] > depth[v]) swap(u,v);
	
	int diff = depth[v] - depth[u];
	
	// Bring both nodes at same minimum height from root
	for(int i=0;i<level;i++)
	{
		if((diff>>i)&1) v = parent[v][i];
	}	
	
	if(u==v) return u;
	
	for(int i=level-1;i>=0;i--)
	{
		if(parent[u][i]!=parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	
	return parent[u][0];
}

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		tree[u].pb(v);
		tree[v].pb(u);
	}
	
	dfs(1,0);
	precompute(n);
	
	int q;
	cin>>q;
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		
		cout<< lca(u,v) << endl;
	}
	
	return 0;
}
