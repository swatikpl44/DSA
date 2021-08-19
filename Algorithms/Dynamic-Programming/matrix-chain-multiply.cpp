// Similar to matrix chain multiplication
// T.C of recursive soln is exponential
// T.C of recursion + memoization is O(n^3) since there are n^2 unique subproblems and
// each subproblem taken O(n) time since it can have n splits
    
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int i, int j) {
        
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MIN;
        for(int k = i; k <= j - 1; k++) {
            ans = max(ans, solve(nums, i, k) + solve(nums, k + 1, j) + nums[i - 1] * nums[k] * nums[j]);
        }
        
        return dp[i][j] = ans;
    }
    
    int matrixMultiplication(int n, vector<int> arr)
    {
        dp.resize(n, vector<int> (n, -1));
        
        return solve(arr, 1, n - 1);
    }
