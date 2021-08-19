#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

/* You are given a tree, rooted at 1, with N vertices (indexed from 1 to N). Each vertex has a value associated with it. 
   The value of ith vertex is a[i]. Consider f[i] as the a[i]th beautiful number. A beautiful number is a positive number, 
   whose sum of the square of its digits is less than or equal to X. You have to process M queries, where each query can be :
   Query 1- 1iy - Update a[i] = y. 
   Query 2- 2i — Output the sum of for all the nodes in the sub-tree of node i (including node i), 
   since the output can be very large, answer it modulo 998244353
*/

/* Solution Appraoch - 
   (i) Push all beautiful numbers ( not more than 5x10^5 numbers, as per constraints ) in an array, generated using BFS.

   (ii) Then, convert the tree to linear array, using DFS so that it's easy to access the subtree of a node, easily. If you don't know, this technique, view it here
        https://discuss.codechef.com/t/a-technique-to-convert-tree-to-a-linear-array-for-efficient-query-processing/9298

   (iii) Use a Fenwick tree (BIT) over this array for queries. 
   
*/

int n, m, x;
const int MOD =  998244353;
const int NN = 5 * 1e5 + 5;
vector<int> beauty, nodes, in, out;
vector<vector<int>> graph;
int tot;

// Function to calculate ith beautiful value
void preprocess()
{
    queue<pair<int, ll>> q;
    
    q.push(make_pair(0, 0ll));
    
    while((int)beauty.size() < NN)
    {
        auto t = q.front(); 
		q.pop();
		
        beauty.emplace_back(t.first);
        
        for(int i = 0; i < 10; i++)
        {
            if(i == 0 && t.first == 0) continue;
            
			if(t.second + i * i <= x)
                q.push({(t.first * 10 + i) % MOD, t.second + i * i});
        }
    }
}

// DFS and euler tour to use tree as a linear array
void dfs(int i, int par)
{
   nodes.push_back(i);
   
   in[i] = tot++;
   for(auto it: graph[i])
    {
        if(it != par)
            dfs(it, i);
    }
    
   out[i] = tot - 1;
}

class BIT
{
    // 1-based indexing    
    vector<int> bit;
    int n;
    
    public:
    BIT(int sz)
    {
        n = sz;
        bit.assign(n + 1, 0);
    }
    
    void update(int x, int del)
    {
        // queries are 1-based
        while(x <= n)
        {
            bit[x] = (((bit[x] + (del % MOD)) % MOD) + MOD) % MOD;
            x+=x&(-x);
        }
    }
    
    int query(int x)
    {
        int ans = 0;
        
        while(x > 0)
        {
            ans = (ans + bit[x]) % MOD;
            ans = (ans + MOD) % MOD;
            x-=x&(-x);
        }
        
        return ans;
    }  
	  
    int query(int l, int r) {
        return (((query(r) - query(l-1)) % MOD) + MOD) % MOD;
    }
    
};

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> x;
	
	graph.resize(n + 1);
	for(int i = 0; i < n - 1; i++)
    {
      int u, v;
      cin >> u >> v;
	        
      graph[u].push_back(v);
      graph[v].push_back(u);      
    } 
	
	preprocess();
	
    in.resize(n + 1);
    out.resize(n + 1);
    nodes.pb(0);               // dummy node as 1-based indexing is done
    
    tot = 1;
    dfs(1, 0);
    
    vector<int> val(n + 1);
    BIT b(n);
    
    for(int i = 1; i <= n; ++i)
    {
      cin >> val[i];
      int ind = val[i];
      b.update(in[i], beauty[ind]);
    }
	
    while(m--)
    {
      int type;
      cin >> type;
      
      if(type == 1) {
      	
          int i, y;
          cin >> i >> y;
          
          int prev = beauty[val[i]];
          int curr = beauty[y];
          int del = curr - prev;
          
          b.update(in[i], del);
          val[i] = y;
          
      } else {
          int i;
          cin >> i;
          
          int l = in[i];
          int r = out[i];
          cout << b.query(l, r) << endl;
      }
  } 
    
	return 0;
}
