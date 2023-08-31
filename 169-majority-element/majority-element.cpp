class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size();
        unordered_map<int,int> mp;
        for(auto n:nums){
            mp[n]++;
            if(mp[n]>len/2){
                return n;
            }
        }
        return 0;
    
    }
};