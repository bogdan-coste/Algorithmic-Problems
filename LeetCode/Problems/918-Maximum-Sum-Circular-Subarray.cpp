#include <climits>
#include <iostream>
#include <vector>
#include <queue>

int maxSubarraySumCircular(std::vector<int>& nums) {
    int total = 0;
    int maxEnding = 0, maxSoFar = INT_MIN;
    int minEnding = 0, minSoFar = INT_MAX;

    for (int x : nums) {
        total += x;

        maxEnding = std::max(x, maxEnding + x);
        maxSoFar = std::max(maxSoFar, maxEnding);

        minEnding = std::min(x, minEnding + x);
        minSoFar = std::min(minSoFar, minEnding);
    }

    if (maxSoFar < 0) return maxSoFar;

    return std::max(maxSoFar, total - minSoFar);
}

int main() {

    std::vector<int> nums = {5,-3,5};

    std::cout << maxSubarraySumCircular(nums) << std::endl;
}
