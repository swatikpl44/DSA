#include<bits/stdc++.h>
using namespace std;
#define rep(i,a)        for(int i = 0 ; i < a ; i++)
bool subsetsum(vector<int>& ans,int sum)
{
	int sz = ans.size();
	bool store[sz+1][sum+1];
	
	rep(i,sum+1) store[0][i] = false;
	rep(j,sz+1) store[j][0] = true;
	
	for(int i=1;i<sz+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(ans[i-1]<=j) store[i][j] = (store[i-1][j-ans[i-1]] or store[i-1][j]);
			else store[i][j] = store[i-1][j];
		}
	}
	return store[sz][sum];
}

int main()
{
	int n,sum;
	cin>>n>>sum;
	
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	if(subsetsum(v,sum)) cout<<"Yes\n";
	else cout<<"No\n";
	
	return 0;
}
