#include<bits/stdc++.h>
using namespace std;
#define rep(i,a)        for(int i = 0 ; i < a ; i++)

// Similar to subset sum, rod cutting etc problems with some base case modifications

int unbounded_knapsack(vector<int>& weight,vector<int>& val,int w,int n)
{
	vector<int> dp(w + 1, 0);
        
        for(int wt = 1; wt <= w; wt++) {
            for(int i = 1; i <= n; i++) {
                if(weight[i - 1] <= wt) {
                    dp[wt] = max(dp[wt], val[i - 1] + dp[wt - weight[i - 1]]);
                }
            }
        }
        
        return dp[w];
}

int main()
{
	int n,weight;
	cin>>n>>weight;
	
	vector<int> wt(n),val(n);
	rep(i,n) cin>>wt[i];
	rep(i,n) cin>>val[i];
	
	int ans = unbounded_knapsack(wt,val,weight,n);
	cout<<ans<<endl;
	
	return 0;
}
