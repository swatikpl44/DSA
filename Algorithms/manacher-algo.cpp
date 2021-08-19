class Solution {
public:
    // O(n) using Manacher's algo
    // Refer to cp algorithms
    string longestPalindrome(string s) {
        
        int n = s.length();
        
        int len = 0, idx = -1;
        
        // Odd sized palindromes
        vector<int> odd(n, 0);
        for(int i = 0, l = 0, r = -1; i < n; i++) {
            
            int k = (i > r) ? 1 : min(odd[l + r - i], r - i + 1);
            
            // Expand at center trivial approach
            while(i - k >= 0 and i + k < n and s[i - k] == s[i + k]) {
                k++;
            }
            
            odd[i] = k--;
            // Update l and r to the rightmost sub palindrome
            if(i + k > r) {
                l = i - k;
                r = i + k;
            }
            
            // Compare with max length palindrome
            if(len < 2 * odd[i] - 1) {
                len = 2 * odd[i] - 1;
                idx = l;
            }
        }
        
        // Even sized palindromes
        vector<int> even(n, 0);
        for(int i = 0, l = 0, r = -1; i < n; i++) {
            
            // Since even palindrome has 2 centres, consider i as the latter index
            // Single letter is not an even palindrome so 0 (if i > r)
            int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
            
            // Expand at center trivial approach
            while(i - k - 1 >= 0 and i + k < n and s[i - k - 1] == s[i + k]) {
                k++;
            }
            
            even[i] = k--;
            // Update l and r to the rightmost sub palindrome
            if(i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
            
            // Compare with max length palindrome
            if(len < 2 * even[i]) {
                len = 2 * even[i];
                idx = l;
            }
        }
        
        
        string ans = "";
        ans = s.substr(idx, len);
        
        return ans;
    }
};
