#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int NN = 1e5;
vector<int> size(NN) , parent(NN);

// logn 
int findparent(int x)
{
	if(x==parent[x]) return x;
	
	return parent[x] = findparent(parent[x]);
}

void unionn(int x,int y)
{
	x = findparent(x);
	y = findparent(y);
	
	if(x!=y)
	{
		if(size[x]<size[y])
		{
			size[y] += size[x];
			parent[x] = y;
		}
		else
		{
			size[x] += size[y];
			parent[y] = x;
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++) size[i] = 1, parent[i] = i;
	
	int x,y;
	int cnt = 0, maxsize = 0;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		
		unionn(x,y);
		maxsize = max(maxsize, size[findparent(x)]);
	} 
	
	for(int i=0;i<n;i++)
	{
		if(findparent(i)==i) cnt++;
	}
	
	cout<< cnt << " " << maxsize <<endl;
	return 0;
}
