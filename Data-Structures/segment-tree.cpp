#include<bits/stdc++.h>
using namespace std;

// Range Min query example
void buildtree(int ar[], int tree[], int index, int s, int e)
{
	if(s==e)
	{
		tree[index] = ar[s];
		return;
	}
	
	int mid = (s+e)/2;
	buildtree(ar,tree,2*index,s,mid);
	buildtree(ar,tree,2*index+1,mid+1,e);
	
	tree[index] =  min(tree[2*index],tree[2*index+1]);
}

int queryans(int tree[],int index,int qs,int qe,int s,int e)
{
	if(qe<s or qs>e) return INT_MAX;
	
	if(qs<=s and qe>=e) return tree[index];
	
	int mid = (s+e)/2;
	int left = queryans(tree,2*index,qs,qe,s,mid);
	int right = queryans(tree,2*index+1,qs,qe,mid+1,e);
	
	return min(left,right);
}

void updatenode(int tree[],int index, int pos, int val, int s, int e)
{
	if(pos<s or pos>e) return;
	
	if(s==e)
	{
		tree[index]+=val;
		return;
	}
	
	int mid = (s+e)/2;
	updatenode(tree,2*index,pos,val,s,mid);
	updatenode(tree,2*index+1,pos,val,mid+1,e);
	
	tree[index] =  min(tree[2*index], tree[2*index+1]);
}

void updaterange(int tree[], int index, int val, int us, int ue, int s, int e)
{
	if(ue<s or us>e) return;
	
	if(s==e)
	{
		tree[index]+=val;
		return;
	}
	
	int mid = (s+e)/2;
	updaterange(tree,2*index,val,us,ue,s,mid);
	updaterange(tree,2*index+1,val,us,ue,mid+1,e);
	
	tree[index] = min(tree[2*index], tree[2*index+1]);
}

int main()
{
	int n;
	cin>>n;
	
	int ar[n];
	for(int i=0;i<n;i++) cin>>ar[i];
	
	int tree[4*n+1];
	int start = 0, end = n-1;
	buildtree(ar,tree,1,start,end);
	
	int q;
	cin>>q;
	
	while(q--)
	{
		int type;
		cin>>type;
		
		if(type==0)
		{
			int l,r;
			cin>>l>>r;
			
			l--;
			r--;
			cout<< queryans(tree,1,l,r,start,end) <<endl;
		}
		else if(type==1)
		{
			int pos,val;
			cin>>pos>>val;
			
			pos--;
			updatenode(tree,1,pos,val,start,end);
		}
		else if(type==2)
		{
			int l,r,val;
			cin>>l>>r>>val;
			
			l--;
			r--;
			updaterange(tree,1,val,l,r,start,end);
		}
	}
	
	return 0;
}
