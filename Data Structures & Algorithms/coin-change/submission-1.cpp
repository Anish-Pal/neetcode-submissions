class Solution {
public:
    int solve(vector<int>& dp , vector<int>& coins , int amount){
        dp[0] = 0;
        for(int i = 1 ; i <= amount ; i++){
            for(int j = 0 ; j < coins.size() ; j++){
                if(i - coins[j] >= 0){
                    dp[i] = min(dp[i] , 1 + dp[i - coins[j]]);
                }
            }
           
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount + 1 , 1e9);
        int ans = solve(dp , coins , amount);
        if(ans == 1e9) return -1;
        return ans;
    }
};