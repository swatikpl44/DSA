// Range sum query with range updates
#include<bits/stdc++.h>
using namespace std;
const int NN = 1e5;
int ar[NN];
int tree[4*NN+1];
int lazy[4*NN+1];

void buildtree(int index, int s, int e)
{
	if(s==e)
	{
		tree[index] = ar[s];
		return;
	}
	
	int mid = (s+e)/2;
	buildtree(2*index,s,mid);
	buildtree(2*index+1,mid+1,e);
	
	tree[index] = tree[2*index] + tree[2*index+1];
}

void updaterange(int index, int rs, int re, int s, int e, int val)
{
	if(lazy[index]!=0)
	{
		tree[index] += ((e-s+1) * lazy[index]);
		if(s!=e)
		{
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index]; 
		}
		lazy[index] = 0;
	}
	
	if(rs>e or re<s) return;
	
	if(rs<=s and re>=e)
	{
		tree[index] += ((e-s+1) * val);
		if(s!=e)
		{
			lazy[2*index] += val;
			lazy[2*index+1] += val;
		}
		return;
	}
	
	int mid = (s+e)/2;
	updaterange(2*index,rs,re,s,mid,val);
	updaterange(2*index+1,rs,re,mid+1,e,val);
	
	tree[index] = tree[2*index] + tree[2*index+1];
}

int queryans(int index, int qs, int qe, int s, int e)
{
	if(lazy[index]!=0)
	{
		tree[index] += ((e-s+1) * lazy[index]);
		if(s!=e)
		{
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index] = 0;
	}
	
	if(qs>e or qe<s) return 0;
	
	if(qs<=s and qe>=e)
	{
		return tree[index];
	}
	
	int mid = (s+e)/2;
	return queryans(2*index,qs,qe,s,mid) + queryans(2*index+1,qs,qe,mid+1,e);
}

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>ar[i];
	
	int start = 0, end = n-1;
	buildtree(1,start,end);
	
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		
		if(type==0)
		{
			int l,r,val;
			cin>>l>>r>>val;
			
			updaterange(1,l-1,r-1,start,end,val);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			cout<< queryans(1,l-1,r-1,start,end) <<endl;
		}
	}
	return 0;
}
