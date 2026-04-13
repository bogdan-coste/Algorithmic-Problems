class Solution {
public:

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    const int m = static_cast<int>(nums1.size());
    const int n = static_cast<int>(nums2.size());
    const int totalLeft = (m + n + 1) / 2;

    int left = 0, right = m;

    while (left <= right) {
        int partition1 = (left + right) / 2;
        int partition2 = totalLeft - partition1;

        const int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        const int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
        const int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        const int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        if (std::max(maxLeft1, maxLeft2) <= std::min(minRight1, minRight2)) {
            if ((m + n) % 2 == 0) {
                return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
            }

            return std::max(maxLeft1, maxLeft2);
        }

        if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        } else {
            left = partition1 + 1;
        }
    }

    return 0.0;
}
};
