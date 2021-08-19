#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
vector<char> pathdir;
int lcs(string& a,string& b,int n,int m)
{	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; 
		else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	}
	
	return dp[n][m];
}

void path(string& a,string& b,int n,int m)
{
	int i=n,j=m;
	while(i>0 and j>0)
	{
		if(a[i-1]==b[j-1])
		{
			pathdir.push_back(a[i-1]);
			i--;
			j--;
		}
		else
		{
			if(dp[i-1][j]==dp[i][j]) i--;
			else j--;
		}
	}
	
	reverse(pathdir.begin(),pathdir.end());
}
int main()
{
	string a,b;
	cin>>a>>b;
	int n=a.length();
	int m=b.length();
	
	int ans = lcs(a,b,n,m);
	cout<<ans<<endl;
	
	path(a,b,n,m);
	cout<<"Path: ";
	for(char x:pathdir) cout<<x;
	return 0;
}
