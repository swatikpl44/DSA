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
int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    /*while(t--)
    {
    	solve();
	}*/
	int n,e,i,j,x,y,w,k;
	cin>>n>>e;
	int v[n+1][n+1];
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(i==j) v[i][j]=0;
		else v[i][j]=1e9;
	}
	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		v[x][y]=w;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		cout<<v[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
