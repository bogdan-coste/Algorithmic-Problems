#include <climits>
#include <iostream>
#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target) {

    std::vector<int> res;

    int left = 0;
    int vecSize = nums.size();
    int right = static_cast<int>(nums.size() - 1);
    int pos = -1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            pos = mid;
            break;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (pos != -1) {

        int up = pos;
        int down = pos;

        while (up < vecSize && nums[up] == target) {
            up++;
        }

        while (down >= 0 && nums[down] == target) {
            down--;
        }

        res.push_back(down + 1);
        res.push_back(up - 1);

    } else {
        res.push_back(-1);
        res.push_back(-1);
    }

    return res;
}

int main() {
    std::vector<int> nums1 = {1};
    int target = 1;

    std::vector<int> res = searchRange(nums1, target);
    for (int x: res) {
        std::cout << x << " ";
    }
}
