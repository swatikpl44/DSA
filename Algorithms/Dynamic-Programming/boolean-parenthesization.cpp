class Solution{
public:
    int dp[200][200][2];
    
    int solve(string s, int i, int j, int istrue) {
        
        if(i == j) {
            if(istrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if(dp[i][j][istrue] != -1 ) return dp[i][j][istrue];
        
        int ans = 0;
        for(int k = i + 1; k < j; k += 2) {
            
            int leftT, leftF, rightT, rightF;
             
            if(dp[i][k-1][1] == -1)
            leftT = solve(s, i, k-1, 1);
            else leftT = dp[i][k-1][1];
            
            if(dp[i][k-1][0] == -1)
            leftF = solve(s, i, k-1, 0);
            else leftF = dp[i][k-1][0];
            
            if(dp[k+1][j][1] == -1)
            rightT = solve(s, k+1, j, 1);
            else rightT = dp[k+1][j][1];
            
            if(dp[k+1][j][0] == -1)
            rightF = solve(s, k+1, j, 0);
            else rightF = dp[k+1][j][0];
            
            if(s[k] == '^') {
                if(istrue) ans += (leftT * rightF) + (leftF * rightT);
                else ans += (leftT * rightT) + (leftF * rightF);
            } else if(s[k] == '&') {
                if(istrue) ans += leftT * rightT;
                else ans += (leftT * rightF) + (leftF * rightT) + (leftF * rightF);
            } else if(s[k] == '|') {
                if(istrue) ans += (leftT * rightT) + (leftF * rightT) + (leftT * rightF);
                else ans += leftF * rightF;
            }
            
            ans = ans % 1003;
        }
        
        return dp[i][j][istrue] = ans % 1003;
    }
    
    int countWays(int n, string s){
        
        memset(dp, -1, sizeof(dp));
        
        return solve(s, 0, n - 1, 1);
    }
};
