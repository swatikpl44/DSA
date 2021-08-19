#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,x;
	cin>>m>>n;
	vector<vector<int>> matrix;
	matrix.assign(n+1,vector<int>());
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>x;
			matrix[i].push_back(x);
		}
	}
	
	// Dynamic Programming
	int ans=0;
    for(int i=0;i<matrix.size();i++)
    {
	    for(int j=0;j<matrix[i].size();j++)
        {
            if(!matrix[i][j]) continue;
            else if(i==0||j==0) ans+=matrix[i][j];
            else{
            matrix[i][j]=min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j]))+1;
            ans+=matrix[i][j];
            }
        }
    }
    cout<<ans;
	return 0;
}
