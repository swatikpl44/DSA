#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
using namespace std;
//using namespace boost::multiprecision;
#define ll unsigned long long
#define vll vector<int> 
#define vllv vector<vector<int> >   //vector of vectors
#define arv vector<int> //ar[10]   array of vectors
#define vpv vector<pair<int,int>>
#define pll pair<int,int> 
#define que queue<int>
#define stk stack<int>
#define mset multiset<pair<int,int>>
#define br "\n"
#define sp " "
const int MOD=1000000007;

vector<pair<ll,ll>> v[1000001]; // array of vector pairs

// Single source shortest path

// Worst case time-complexity is O(|V|*|V|)
// V vertices for which we need to find the shortest distance
// For each vertex, there can be atmost |V| edges

// Drawback: May or may not work with negative weight edges
void dijkstra(int n)
{
	ll dist[n+1],i,j;
	
	bool vis[n+1];
	
	for(i=1;i<=n;i++)
	{
		dist[i]=1e9;
		vis[i]=false;
	}
	
	// Based on greedy strategy
	
	// pick the vertex that is currently nearest(or shortest)
	// Use this vertex to check distances of its neighbors and continue..
	multiset<pair<int,int>>s;
	
    s.insert({0,0});
    
    // We start from vertex 0
	dist[0]=0;
	
	while(!s.empty())
	{
		 pair<int,int> p = *s.begin();
         s.erase(s.begin());
         
         ll from = p.second;
         vis[from]=1;
         
		 for(j=0;j<v[from].size();j++)
		 {
		 	ll to = v[from][j].second;
		 	ll cost = v[from][j].first;
		 	
		 	if(!vis[to] and dist[from] != 1e9 and cost + dist[from] < dist[to])
		 	{
		        dist[to] = dist[from] + cost;
		        s.insert({dist[to],to});
			}
		 }
	}
	
	for(i=1;i<n;i++) cout<<dist[i]<<endl;
}
int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    /*while(t--)
    {
    	solve();
	}*/
	int n,e,i,x,y,w;
	cin>>n>>e;
	
	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;;
		v[x].push_back({w,y});
		v[y].push_back({w, x});
	}
	
	dijkstra(n);
	return 0;
}
