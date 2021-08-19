/**
 * Author : Swatik Paul [swatikpl44]
 */
 
#include <bits/stdc++.h>
using namespace std;
#define fastIO         ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll             long long
#define rep(i,a)       for(ll i = 0 ; i < a ; i++)
#define endl           "\n"	
#define ff			first
#define ss			second

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;
vector<vector<int>> adj1;

const int INF = 1e7;

void bfs2(int node) {	
	
	queue<int> q;
	vector<bool> vis(n, false);
	q.push(node);
	
	vis[node] = true;
	
	while(!q.empty())
	{
		int f = q.front();
		
		for(int x: adj1[f]) {
			if(vis[x] == false) {
				q.push(x);
				vis[x] = true;
			}
		}
		
		for(int x: adj1[f]) {
			cout << f << " " << x << " " << capacity[f][x] << endl;
			//cout << x << " " << f << " " << capacity[x][f] << endl;
		}
		
		q.pop();
	}
}

int bfs(int s, int t, vector<int>& parent) {
	
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
    	
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
        	
            if (parent[next] == -1 && capacity[cur][next]) {
            	
                parent[next] = cur;
                
                int new_flow = min(flow, capacity[cur][next]);
                
                if (next == t)
                    return new_flow;
                    
                q.push({next, new_flow});
                
            }
            
        }
        
    }

    return 0;
}

int maxflow(int s, int t) {
	
    int flow = 0;
    vector<int> parent(n);
    
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
    	
    	cout << "---------------------------------------------------------------\n";
        flow += new_flow;
        int cur = t;
        
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
        
        bfs2(0);
//        for(int i = 0; i < n; i++) {
//        	for(int j = 0; j < n; j++) {
//        		cout << i << " " << j << ": " << capacity[i][j] << endl;
//			}
//			cout << endl;
//		}
    }

    return flow;
}
 
int main() {
	fastIO;
    
    cin >> n;
    
    capacity.resize(n + 1, vector<int> (n + 1, 0));
    adj.resize(n + 1, vector<int> ());
    adj1.resize(n + 1, vector<int> ());
    
    int m;
    cin >> m;
    
    rep(i, m) {
    	int x, y, val;
    	cin >> x >> y >> val;
    	
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    	
    	adj1[x].push_back(y);
    	capacity[x][y] = val;
	}
	
	cout << maxflow(0, n - 1) << endl;
	
    return 0;
}
