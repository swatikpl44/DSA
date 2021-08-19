#include<bits/stdc++.h>
using namespace std;
#define rep(i,a)        for(int i = 0 ; i < a ; i++)
int knapsack(vector<int>& wt,vector<int>& val,int weight,int n)
{
	int store[n+1][weight+1];
	
	rep(i,n+1) rep(j,weight+1) if(i==0||j==0) store[i][j]=0;
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<weight+1;j++)
		{
			if(wt[i-1]<=j) store[i][j] = max( val[i-1] + store[i-1][j-wt[i-1]] , store[i-1][j]);
			else store[i][j] = store[i-1][j];
		}
	}
	return store[n][weight];
}

int main()
{
	int n,weight;
	cin>>n>>weight;
	
	vector<int> wt(n),val(n);
	rep(i,n) cin>>wt[i];
	rep(i,n) cin>>val[i];
	
	int ans = knapsack(wt,val,weight,n);
	cout<<ans<<endl;
	
	return 0;
}
