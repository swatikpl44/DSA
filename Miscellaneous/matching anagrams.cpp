#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,p;
	cin>>s>>p;
	vector<int> count_p(26,0),count_s(26,0);
	vector<int> result;
	
	for(char ch:p) count_p[ch-'a']++;
	for(int i=0;i<s.size();i++)
	{
		if(i<p.size()-1) count_s[s[i]-'a']++;
		else{
			count_s[s[i]-'a']++;
			if(count_s==count_p)  result.push_back(i-p.size()+1);
			count_s[s[i-p.size()+1]-'a']--;
		}
	}
	for(int index:result)
	cout<<index<<" ";
	return 0;
}
