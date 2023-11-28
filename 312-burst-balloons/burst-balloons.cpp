
class Solution {
public:
    int maxCoins(vector<int>& nums) {
       int n=nums.size();
       nums.insert(nums.begin(), 1);
       nums.push_back(1);
       vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
       for(int l=1;l<=n;l++) {
           for(int i=1;i<=n-l+1;i++) {
               int j=i+l-1;
               for(int k=i;k<=j;k++)
               {
                   int cost=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                   dp[i][j]=max(dp[i][j], cost);
               }
           }
       }
       return dp[1][n];
    }
};