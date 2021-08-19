// minimise no of coins to make a given amount with coin values given
#include<bits/stdc++.h>
using namespace std;
int unbounded_knapsack(vector<int>& coins,int amount,int n)
{
	int store[n+1][amount+1]={{0}};
	
	// store[i][j] tells the minimum no of coins required to achieve amount j by using first i coins
	for(int i=0;i<=n;i++) 
	for(int j=0;j<=amount;j++)
	{
		if(i==0) store[i][j]=INT_MAX-1;
		if(j==0) store[i][j]=0;
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=amount;j++)
	{
		if(coins[i-1]<=j) store[i][j] = min(store[i-1][j] ,1+store[i][j-coins[i-1]]);
		else store[i][j] = store[i-1][j];
	}
	return store[n][amount];
}

int main()
{
	int amount;
	cin>>amount;
	
	int n;
	cin>>n;
	
	vector<int> coins(n);
	for(int i=0;i<n;i++) cin>>coins[i];
	
	int ans=unbounded_knapsack(coins,amount,n);
	cout<<ans<<endl;
	return 0;
}
