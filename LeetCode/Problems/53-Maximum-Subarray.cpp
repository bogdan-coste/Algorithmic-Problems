class Solution {
public:
int maxSubArray(vector<int>& nums) {
    int maxi=nums[0]; 
    int currentSum=nums[0];
    for(int i=1;i<nums.size();i++) {
        currentSum=max(nums[i],currentSum+nums[i]);
        maxi=max(maxi,currentSum);
    }
    return maxi;
}
};
