#include<bits/stdc++.h>
using namespace std;
int maxcircularsub(vector<int> &v)
{
	    int max_current=v[0],min_current=v[0];
	    int max_global=v[0],min_global=v[0];
        int sum =v[0];
	    for(int i=1;i<v.size();i++)
	    {
            sum+=v[i];
		    max_current=max(v[i],max_current+v[i]);
            min_current=min(v[i],min_current+v[i]);
		    if(max_current>max_global) max_global=max_current;
            if(min_current<min_global) min_global=min_current;
	    }
        int ans;
        if(sum!=min_global) ans=max(max_global,sum-min_global);
        else ans=max_global;
        cout<<ans<<endl;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++) cin>>v[i];
	
	int max_current=v[0];
	int max_global=v[0];
	for(int i=1;i<n;i++)
	{
		max_current=max(v[i],max_current+v[i]);
		if(max_current>max_global) max_global=max_current;
	}
	maxcircularsub(v);
	cout<<max_global<<endl;
	return 0;
}
