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
vllv v;

// Single source shortest path

// Based on DP strategy
// Relaxes each edge |V|-1 times
// So, time complexity is O(|V|*|E|) 
// Worst case can be O(n^3) in case of a complete graph where |E| = (n*(n-1))/2 (n is no. of vertices)

// Drawback: Doesn't work for negative weight cycle
int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    /*while(t--)
    {
    	solve();
	}*/
	int n,e,i,j,x,y,w;
	cin>>n>>e;
	
	ll dist[n+1];
	
	v.assign(e+1,vll());
	
	for(i=1;i<=n;i++) dist[i]=INT_MAX;
	
	dist[1]=0;
	
	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		v[i].push_back(x);
		v[i].push_back(y);
		v[i].push_back(w);
	}
	
	for(i=0;i<n-1;i++)
	{
		j=0;
		while(j < e)
		{
			if(dist[v[j][0]] + v[j][2] < dist[v[j][1]]) dist[v[j][1]] = dist[v[j][0]] + v[j][2];
			
			j++;
		}
	}
	
	for(i=1;i<=n;i++) cout<<dist[i]<<endl;
	
	return 0;
}
