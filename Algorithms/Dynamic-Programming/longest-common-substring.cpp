#include<bits/stdc++.h>
using namespace std;
int lcs(string& a,string& b,int n,int m)
{
	int dp[n+1][m+1];
	
	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	{
		if(i==0 or j==0) dp[i][j]=0;
	}
	
	int maxi = INT_MIN;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; 
		else dp[i][j] = 0;
		
		maxi = max(maxi,dp[i][j]);
	}
	
	return maxi;
}

int main()
{
	string a,b;
	cin>>a>>b;
	int n=a.length();
	int m=b.length();
	
	int ans = lcs(a,b,n,m);
	cout<<ans<<endl;
	return 0;
}
