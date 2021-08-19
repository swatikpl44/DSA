#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n;
int BIT[N*2];

void update(int index, int val)
{
	index++;
	while(index<=n)
	{
		BIT[index]+=val;
		index += (index & -index);
	}
}

int findsum(int index)
{
	int sum = 0;
	while(index>0)
	{
		sum+=BIT[index];
		index -= (index & -index);
	}
	return sum;
}

int sum(int l,int r)
{
	return findsum(r) - findsum(l-1);
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n;
	
	int ar[n];
	for(int i=0;i<n;i++) 
	{
		cin>>ar[i];
		update(i,ar[i]);
	}
	
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,type;
		cin>>type;
		
		if(type==0)
		{
			int pos,val;
			cin>>pos>>val;
			update(pos-1,val);
		}
		else
		{
			cin>>l>>r;
			cout<< sum(l,r) <<endl;
		}
	}
	return 0;
}
