#include<bits/stdc++.h>
using namespace std;
#define rep(i,a)        for(int i = 0 ; i < a ; i++)

string findString(string s, string t) {
	int n = s.size();
	int m = t.size();
	
	vector<vector<int>> dp;
	dp.resize(n, vector<int> (m, -1));
	
	for(int i = 0; i < n; i++) {
		if(s[i] == t[0]) dp[i][0] = i;
		else if(i > 0) dp[i][0] = dp[i - 1][0];
	}
	
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = dp[i - 1][j];
		}
	}
	
	int start = -1, len = INT_MAX;
	for(int i = 0; i < n; i++) {
		int idx = dp[i][m - 1];
		
		if(idx != -1) {
			int curr = i - idx + 1;
			if(curr < len) {
				len = curr;
				start = idx;
			}
		}
	}
	
	if(start == -1) return "";
	return s.substr(start, len);
}

int main()
{
	string s, t;
	cin >> s >> t;
	
	cout << findString(s, t) << endl;
	
	return 0;
}
