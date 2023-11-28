class Solution {
public:
    int n;
    int t[501][501]; 
    int solve(vector<int> &nums, int i, int j){
		if(i > j)
			return 0;
        if(i == j){   
            int temp = nums[i];
            if(i - 1 >= 0)  
                temp *= nums[i - 1];
            if(i + 1 < n)
                temp *= nums[i + 1];
            return temp;
        }
		if(t[i][j] != -1) 
			return t[i][j];
        int ans = 0;
		
		
        for(int k = i; k <= j; k++){
		
		    
            int temp = nums[k];
			
            if(j + 1 < n)  
                temp *= nums[j + 1];
				
            if(i - 1 >= 0) 
                temp *= nums[i - 1];
 temp += (solve(nums, i, k - 1) + solve(nums, k + 1, j));
			
			
            ans = max(ans, temp);
        }
        return t[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(t, -1, sizeof(t));
		
        
		vector<int> arr = {1};
        for(int x: nums) 
			arr.push_back(x);
        arr.push_back(1);
        n = arr.size();
		
		
        return solve(arr, 1, arr.size() - 2);
    }
};