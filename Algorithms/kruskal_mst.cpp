#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll, pair<ll, ll>> adj[100005];
vector<int> id(1e4 + 5);
int n, m;

void initialize(int x) {
    for(int i = 0; i < x; i++)
        id[i] = i;
}

int root(int x) {
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(ll x, ll y) {
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

// O(ElogV)
ll kruskal()
{
    ll x, y;
    ll cost, minCost = 0;

    for(int i = 0; i < m; i++)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = adj[i].second.first;
        y = adj[i].second.second;
        cost = adj[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minCost += cost;
            union1(x, y);
        }    
    }
    return minCost;
}

int main() {
	
	cin >> n >> m;

	initialize(n);

	for(int i = 0; i < m; i++) {
		ll x, y, w;
		cin >> x >> y >> w;

		adj[i] = make_pair(w, make_pair(x, y));
	}

	sort(adj, adj + m);

	cout << kruskal() << endl;
	
	return 0;

}



