#include <climits>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            
            sum = std::max(nums[i], sum + nums[i]);
            maxi = std::max(maxi, sum);
        }

        return maxi;
    }
};

int main(){
    
}
