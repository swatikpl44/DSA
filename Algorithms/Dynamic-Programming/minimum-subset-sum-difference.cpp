#include<bits/stdc++.h>
using namespace std;
#define rep(i,a)        for(int i = 0 ; i < a ; i++)
int subsetsum(vector<int>& ar,int sum)
{
	int sz = ar.size();
	bool store[sz+1][sum+1];
	
	rep(i,sum+1) store[0][i] = false;
	rep(j,sz+1) store[j][0] = true;
	
	for(int i=1;i<sz+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(ar[i-1]<=j) store[i][j] = (store[i-1][j-ar[i-1]] or store[i-1][j]);
			else store[i][j] = store[i-1][j];
		}
	}
	
	for(int i=sum/2;i>=0;i--)
	{
		if(store[sz][i]) return (sum-2*i);
	}
}

int main()
{
	int n;
	cin>>n;
	
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	
	int sum=0;
	rep(i,n) sum+=v[i];
	int ans = subsetsum(v,sum);
	cout<<ans<<endl;
	
	return 0;
}
