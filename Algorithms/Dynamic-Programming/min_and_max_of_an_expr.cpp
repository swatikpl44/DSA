#include<bits/stdc++.h>
using namespace std;

/*	Given an expression which contains numbers and two operators ‘+’ and ‘*’, we need to find maximum and minimum value 
	which can be obtained by evaluating this expression by different parenthesization. 
	
	O(n^3) similiar to M.C.M
*/

vector<vector<int>> dp1;
int findMax(string s, int i, int j) {
	
	if(i > j) return 0;
	if(i == j) return s[i] - '0';
	
	if(dp1[i][j] != -1) return dp1[i][j];
	
	int ans = INT_MIN, val;
	for(int k = i + 1; k < j; k += 2) {
		
		if(s[k] == '+') val = findMax(s, i, k - 1) + findMax(s, k + 1, j);
		else if(s[k] == '*') val = findMax(s, i, k - 1) * findMax(s, k + 1, j);
		
		ans = max(ans, val);
	} 
	
	return dp1[i][j] = ans;
}

vector<vector<int>> dp2;
int findMin(string s, int i, int j) {
	
	if(i > j) return 0;
	if(i == j) return s[i] - '0';
	
	if(dp2[i][j] != -1) return dp2[i][j];
	
	int ans = INT_MAX, val;
	for(int k = i + 1; k < j; k += 2) {
		
		if(s[k] == '+') val = findMin(s, i, k - 1) + findMin(s, k + 1, j);
		else if(s[k] == '*') val = findMin(s, i, k - 1) * findMin(s, k + 1, j);
		
		ans = min(ans, val);
	} 
	
	return dp2[i][j] = ans;
}

int main() {
	
	string s;
	cin >> s;
	
	int n = s.length();
	
	dp1.resize(n, vector<int> (n, -1));
	cout << findMax(s, 0, n - 1) << endl;
	
	dp2.resize(n, vector<int> (n, -1));
	cout << findMin(s, 0, n - 1) << endl;
	
	return 0;
}
