class Solution {
public:
    int n;
    
    int func(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp){
        if(i == n || k == 0) return 0;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int ans = func(i+1, k, piles, dp); // skip pile
        
        int sum = 0;
        for(int x = 1; x <= piles[i].size() && x <= k; x++){
            sum += piles[i][x-1];
            ans = max(ans, sum + func(i+1, k-x, piles, dp));
        }
        
        return dp[i][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return func(0, k, piles, dp);
    }
};
